//
//  longest_substring_without_repeating_characters.cpp
//  leetCode
//
//  Created by Haag, Austin P on 6/12/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include <stdio.h>
#include "libraries.h"


int lengthOfLongestSubstring(string s) {
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) {
        if (dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}


// MY APPROACH
int lengthOfLongestSubstring1(string s) {
    if (s.length() == 0) return 0;
    
    //vector<int> lastSeen;
    unordered_map<char, int> lastSeen;
//    lastSeen.resize(26, -1);
    vector<int> numAway;
    numAway.resize(s.size());
    iota(numAway.begin(), numAway.end(), 0);
    
    //int convert = 'a';
    for (int i = 0; i < s.size(); ++i) {
        if (lastSeen.find(s[i]) == lastSeen.end()) {
            lastSeen[s[i]] = -1;
        }
        numAway[i] = i - lastSeen[s[i]] - 1;
        lastSeen[s[i]] = i;
    }
    
    int maxSize = 1;
    for (int i = (int)s.size() - 1; i > 0; --i) {
        // explorable
        if (numAway[i] >= maxSize) {
            int numToExplore = numAway[i];
            int testMaxSize = 1;
            while (numToExplore > 0) {
                if (i - testMaxSize > 0 && numAway[i - testMaxSize] < numToExplore) {
                    // numAway of the one we are looking at now
                    numToExplore = numAway[i - testMaxSize];
                } else {
                    --numToExplore;
                }
                ++testMaxSize;
            }
            if (testMaxSize > maxSize) {
                maxSize = testMaxSize;
            }
        }
    }
    
    return maxSize;
}


void run() {
    
    cout << lengthOfLongestSubstring("austina");
}
