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

struct node {
    node *prev;
    node *next;
    int datum;
};


node *insert() {
    node *newNode = new node();
    return newNode;
}


int main() {
    
    cout << endl;
}

