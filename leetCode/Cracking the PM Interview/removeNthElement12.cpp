//
//  removeNthElement12.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include "libraries.h"

// REVIEW

// 16.12
// Write a function which removes the nth element from a queue (but keep all the other elements in place and in the same order)
// Remember to not use template name for parameters

bool removeFromQueue(queue<int> &queueIn, int k) {

    queue<int> temp;
    // DON'T FORGET: USING .SIZE IN A FOR LOOP DOESN'T WORK IF THE SIZE IS CHANGING
    size_t queueSize = queueIn.size();
    for (int i = 1; i <= queueSize; ++i) {
        if (i != k) {
            temp.push(queueIn.front());
        }
        queueIn.pop();
    }
    queueIn = temp;
    return false;
}

void printQueue(queue<int> queueIn) {
    cout << "From front to back: ";
    while (!queueIn.empty()) {
        cout << queueIn.front() << " ";
        queueIn.pop();
    }
    cout << endl;
}

int main() {
    
    queue<int> queueIn;
    queueIn.push(1);
    queueIn.push(2);
    queueIn.push(3);
    queueIn.push(4);
    queueIn.push(5);
    queueIn.push(6);
    queueIn.push(7);
    queueIn.push(8);
    printQueue(queueIn);
    removeFromQueue(queueIn, 5);
    printQueue(queueIn);
    cout << endl;
}



