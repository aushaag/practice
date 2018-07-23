//
//  isSubset_16.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include"libraries.h"


// 16.3
// Given two lists (A and B) of unique strings, write a program to determine if A is a subset of B. That is, check if all the elements from A are contained in B.
bool isSubset(vector<string> smaller, vector<string> bigger) {
    
    // can complete in O(n) using a hash table
    unordered_set<string> biggerWords;
    
    for (auto word : bigger) {
        biggerWords.insert(word);
    }
    
    for (auto word : smaller) {
        if (biggerWords.find(word) == biggerWords.end()) {
            return false;
        }
    }
    return true;
}


int main() {
    
    vector<string> bigger = { "apple", "pear", "orange", "banana" };
    vector<string> smaller = { "apple", "orange" };
    
    cout << isSubset(bigger, smaller) << endl;
    
    cout << isSubset(smaller, bigger) << endl;

    cout << endl;
}
