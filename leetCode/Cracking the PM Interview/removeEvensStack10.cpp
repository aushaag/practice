//
//  removeEvensStack10.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include "libraries.h"


// 16.10
// Write a function which removes all the even numbers from a stack. You should return the original stack, not a new one.

stack<int> removeEvens(stack<int> stack) {
    
    ::stack<int> reversed;
    
    while (!stack.empty()) {
        if (stack.top() % 2 == 1) {
            reversed.push(stack.top());
        }
        stack.pop();
    }
    
    while (!reversed.empty()) {
        stack.push(reversed.top());
        reversed.pop();
    }
    
    return stack;
}


void printStack(stack<int> stack) {
    cout << "From top to bottom: ";
    
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}
int main() {
    
    stack<int> newStack;
    newStack.push(0);
    newStack.push(1);
    newStack.push(2);
    newStack.push(3);
    newStack.push(4);
    newStack.push(5);
    
    printStack(newStack);
    
    printStack(removeEvens(newStack));
    
    cout << endl;
}


