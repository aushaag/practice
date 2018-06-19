//
//  longest_palindromic_substring.cpp
//  leetCode
//
//  Created by Haag, Austin P on 6/15/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include <stdio.h>
#include "libraries.h"

bool palindrome(string s) {
    for (int i = 0; i <= s.size()/2; ++i) {
        if (s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

//int expandAroundCenter(string s, int left, int right) {
//    int L = left, R = right;
//    while (L >= 0 && R < s.length() && s[L] == s[R]) {
//        L--;
//        R++;
//    }
//    return R - L - 1;
//}
//
//
//string longestPalindrome(string x) {
//    if (x.length() == 1) return x;
//    else if (x.length() == 0) return "";
//
//    int start = 0;
//    int end = 0;
//    int len1, len2, len;
//    for (int i = 0; i < (int)x.size(); ++i) {
//        len1 = expandAroundCenter(x, i, i);
//        len2 = expandAroundCenter(x, i, i + 1);
//        len = max(len1, len2);
//        if (len > end - start) {
//            start = i - (len - 1) / 2;
//            end = i + len / 2;
//        }
//    }
//
//    return x.substr(start, end + 1);
//}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
        if (s.size() - i <= max_len / 2) break;
        int j = i, k = i;
        while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
        i = k+1;
        while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
        int new_len = k - j + 1;
        if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
}

// REVERSING THE STRING AND SEEING IF IT MATCHES, THEN VALIDATING IS PALINDROME
string longestCommonSubstring(string x, string y) {
    
    //cout << x.substr(0, 5);
    //palindrome(x.substr(0, 5));
    int m = (int)x.size();
    int n = (int)y.size();
    int longestCommon[m + 1][n + 1];
    int longest = 0;
    int endx = -1;
    int endy = -1;
    
    //int dummy;
    longestCommon[0][0] = 0;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <=n; ++j) {
            longestCommon[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (x[i - 1] == y[j - 1]) {
                longestCommon[i][j] = longestCommon[i - 1][j - 1] + 1;
                if (longestCommon[i][j] > longest) {
                    //dummy = longestCommon[i][j];
                    //cout << x.substr(i - longestCommon[i][j], longestCommon[i][j]);
                    if (palindrome(x.substr(i - longestCommon[i][j], longestCommon[i][j]))) {
                        longest = longestCommon[i][j];
                        endx = i;
                        endy = j;
                    }
                }
            }
        }
    }
    
    return x.substr(endx - longest, longest);
}

// USES LONGEST SUBSTRING OF REVERSED
string longestPalindrome2(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    
    return longestCommonSubstring(s, r);
}



// REQUIRED: Strings must be same size
//string longestCommonSubstring(string s, string r) {
//    bool searching = false;
//    int begin = 0;
//    int longest = 0;
//    int longestBegin = -1;
//    for (int i = 0; i < (int)s.size(); ++i) {
//        if(s[i] == r[i]) {
//            if (!searching) {
//                begin = i;
//                if (1 > longest) longest = 1;
//                if (longest == 1) longestBegin = i;
//                searching = true;
//            } else {
//                if (i - begin > longest) longest = i - begin + 1;
//            }
//        } else {
//            searching = false;
//        }
//    }
//    return s.substr(longestBegin, longest);
//}




void run() {
    cout << longestPalindrome("cbbd");
    //cout << palindrome("abddeba");
    //cout << longestPalindrome("drag-asad-gard");
    //cout << longestPalindrome("abadaba--");
    //cout << longestCommonSubstring("aust--in", "aust-in");
}
