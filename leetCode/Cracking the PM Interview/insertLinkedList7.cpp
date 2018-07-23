//
//  insertLinkedList7.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include"libraries.h"


// 16.7
// Insert a node into a sorted linked list (in order).

struct Node {
    Node *prev;
    Node *next;
    int datum;
};


Node *insert(Node * insert) {
    if (insert == nullptr) {
        insert = new Node();
    }
    Node *newNode = new Node();
    return newNode;
}


int main() {
    Node * sortedList = new Node {nullptr, nullptr, 0};
    
    cout << endl;
}

