//
//  sortBinaryList8.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include"libraries.h"


// 16.8
// "Sort" a linked list that contains just 0s and 1s. That is, modify the list such that all 0s come before all 1s

struct Node {
    Node *next;
    int datum;
    Node(Node * ptr, int datum_in) : next(ptr), datum(datum_in) { }
};



Node *sortBinaryList(Node *list) {
    Node *zeroHead = nullptr;
    Node *zeroTail = nullptr;
    Node *oneHead = nullptr;
    Node *oneTail = nullptr;
    
    while (list) {
        if (list->datum == 0) {
            if (zeroHead) {
                zeroTail->next = new Node(nullptr, 0);
                zeroTail = zeroTail->next;
            } else {
                zeroHead = new Node(nullptr, 0);
                zeroTail = zeroHead;
            }
        } else {
            if (oneTail) {
                oneTail->next = new Node(nullptr, 1);
                oneTail = oneTail->next;
            } else {
                oneHead = new Node(nullptr, 0);
                oneTail = oneHead;
            }
        }
        list = list->next;
    }
    
    if (zeroHead) {
        zeroTail->next = oneHead;
        return zeroHead;
    } else if (oneHead) {
        return oneHead;
    } else {
        return nullptr;
    }
    
}

Node * insertBack(Node* list, int datum) {
    
    if (!list) {
        list = new Node(nullptr, datum);
        return list;
    }
    // now at the back of the tail
    while (list->next) {
        list = list->next;
    }
    
    list->next = new Node(nullptr, datum);
    return list;
    
}

void printList(Node * list) {
    while (list) {
        cout << list->datum << " --> ";
        list = list->next;
    }
    cout << endl;
}


int main() {
    
    Node * list = nullptr;
    
    list = insertBack(list, 0);
    insertBack(list, 0);
    insertBack(list, 0);
    insertBack(list, 1);
    insertBack(list, 0);
    insertBack(list, 1);
    insertBack(list, 1);
    insertBack(list, 1);
    insertBack(list, 0);
    insertBack(list, 0);
    
    printList(list);
    
    list = sortBinaryList(list);
    
    printList(list);
    
    cout << endl;
}

