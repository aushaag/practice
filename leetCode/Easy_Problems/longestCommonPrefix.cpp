//
//  longestCommonPrefix.cpp
//  leetCode
//
//  Created by Haag, Austin P on 6/8/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include <stdio.h>
#include "libraries.h"



string longestCommonSubstring(vector<string>& strs) {
    if (strs.empty()) return "";
    
    sort(strs.begin(), strs.end(), [](string &inString, string &inStr2) {
        if (inString.size() < inStr2.size()) return true;
        else return false;
    });
    
    string shortest = strs[0];
    strs.erase(strs.begin());
    bool found = true;
    while (!shortest.empty()) {
        found = true;
        for (auto str : strs) {
            if (str.find(shortest) == string::npos) {
                found = false;
                break;
            }
        }
        if (found) {
            return shortest;
        }
        else shortest.pop_back();
    }
    
    //    for (auto word : strs) {
    //        cout << word;
    //    }
    return "";
}


string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    
//    struct lessThan {
//        bool operator() (string &inString, string &inStr2) {
//            if (inString.size() < inStr2.size()) return true;
//            else return false;
//        }
//    };
    
//    int shortestString = INT_MAX;
//    for (int i = 0; i < strs.size(); ++i) {
//        if (strs[i].size() < shortestString) {
//            shortestString = i;
//        }
//    }
//
    //sort(strs.begin(), strs.end(), lessThan());
    
    sort(strs.begin(), strs.end(), [](string &inString, string &inStr2) {
        if (inString.size() < inStr2.size()) return true;
        else return false;
    });
    
    string shortest = strs[0];
    strs.erase(strs.begin());
    bool found = true;
    while (!shortest.empty()) {
        found = true;
        for (auto str : strs) {
            for(int i = 0; i < shortest.size(); ++i) {
                if (str[i] != shortest[i]) {
                found = false;
                break;
                }
            }
        }
        if (found) {
            return shortest;
        }
        else shortest.pop_back();
    }

//    for (auto word : strs) {
//        cout << word;
//    }
    return "";
}
    
    void run() {
        vector<string> testVect;
        testVect.push_back("flowers");
        testVect.push_back("flowt");
        testVect.push_back("flower");
        cout << longestCommonPrefix(testVect);
        testVect.push_back("fl");
        cout << longestCommonPrefix(testVect);
        
    }
