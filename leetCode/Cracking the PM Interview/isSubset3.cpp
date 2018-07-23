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
bool isSubset(vector<string> bigger, vector<string> smaller) {
    
    return false;
}


int main() {
    
    vector<string> bigger = { "apple", "pear", "orange" };
    vector<string> smaller = { "apple", "orange" };
    
    isSubset(bigger, smaller);

    cout << endl;
}
