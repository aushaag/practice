//
//  reverseWithoutDestroying9.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include "libraries.h"


// 16.9
// Write a function which takes a stack as input and returns a new stack which has the lements reversed.


stack<int> reverseStack(stack<int> stackIn) {
    
    stack<int> newStack;
    while (!stackIn.empty()) {
        newStack.push(stackIn.top());
        stackIn.pop();
    }
    
    return newStack;
}


stack<int> reverseWithoutDestroying(stack<int> stackIn) {
    stack<int> temp;
    stack<int> reversed;
    
    while (!stackIn.empty()) {
        temp.push(stackIn.top());
        reversed.push(stackIn.top());
        stackIn.pop();
    }
    
    while (!temp.empty()) {
        stackIn.push(temp.top());
        temp.pop();
    }
    
    return reversed;
}

int main() {
    
    cout << endl;
}


