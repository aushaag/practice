//
//  findCelebrity.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include "libraries.h"
// 16.21
// In a group of people, a person is called a celebrity if everyone knows them but they know no one else. You are given a function knows(a, b) which tells you if person a knows person b. Design an algorithm to find the celebrity (if one exists).
// For simplicity, you can assume that everyone is given a label from 0 to N - 1. You need to implement a function int findCelebrity(int N).
// Observe that:
//      1. There can only be one celebrity at most (due to the definition of a cebrity).
//      2. The knows function is the only way to look up who knows who.


bool knows(int person1, int person2) {
    return (rand() % 2 == 1) ? true : false;
}

bool isCelebrity(int people, int candidate) {
    
    return false;
}

int main() {
    
    cout << endl;
}
