//
//  queuesAreEqual11.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include "libraries.h"


// 16.11
// Write a function to check if two queues are identical (same values in the same order)


bool isEqual(queue<int> queue1, queue<int> queue2) {
    if (queue1.size() != queue2.size()) return false;
    
    while (!queue1.empty()) {
        if (queue1.front() != queue2.front()) return false;
        else {
            queue1.pop();
            queue2.pop();
        }
    }
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
    
    cout << endl;
}


