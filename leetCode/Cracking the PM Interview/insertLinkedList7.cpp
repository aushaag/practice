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

// NOTE: REMEMBER THAT THERE IS A DIFFERENCE BETWEEN A LINKED LIST AND A DOUBLY LINKED LIST

// Doubly linked list: remember where insert goes and remember prev, too
Node *insertDoublyLinkedList(Node * list, Node * insert) {
    Node * node = list;
    if (list == nullptr) {
        return insert;
    } else if (node->datum > insert->datum) {
        node->prev = insert;
        insert->next = node;
        return insert;
    }
    
    Node * prev = node;
    node = node->next;
    while(node && node->datum < insert->datum) {
        prev = node;
        node = node->next;
    }
    
    // inserting node to end of the list
    if (!node) {
        prev->next = insert;
        insert->prev = prev;
    }
    //inserting where node is
    else {
        prev->next = insert;
        insert->prev = prev;
        insert->next = node;
        node->prev = insert;
    }
    return list;
    
}

// Singly linked list: find one before where insert goes
Node *insert(Node * list, Node * insert) {
    Node * node = list;
    if (list == nullptr) {
        return insert;
    } else if (node->datum > insert->datum) {
        insert->next = node;
        return insert;
    }
    
    else while (node->next && node->next->datum < insert->datum) {
        node = node->next;
    }
    
    insert->next = node->next;
    node->next = insert;
    return list;
}

void printList(Node * list) {
    while (list) {
        cout << list->datum << " --> ";
        list = list->next;
    }
    cout << endl;
}

void printDoublyLinkedList(Node * list) {
    while (list) {
        cout << list->datum << " --> ";
        if (list->next) {
            list = list->next;
        } else {
            break;
        }
    }
    cout << "END. REVERSING. ";
    while (list) {
        cout << list->datum << " --> ";
        list = list->prev;
    }
    cout << endl;
}

int main() {
    Node * sortedList = new Node {nullptr, nullptr, 0};
    
    sortedList = insertDoublyLinkedList(sortedList, new Node {nullptr, nullptr, 1});
    printDoublyLinkedList(sortedList);
    sortedList = insertDoublyLinkedList(sortedList, new Node {nullptr, nullptr, 5});
    printDoublyLinkedList(sortedList);
    sortedList = insertDoublyLinkedList(sortedList, new Node {nullptr, nullptr, 4});
    printDoublyLinkedList(sortedList);
    sortedList = insertDoublyLinkedList(sortedList, new Node {nullptr, nullptr, 3});
    printDoublyLinkedList(sortedList);
    sortedList = insertDoublyLinkedList(sortedList, new Node {nullptr, nullptr, 7});
    printDoublyLinkedList(sortedList);
    sortedList = insertDoublyLinkedList(sortedList, new Node {nullptr, nullptr, -1});
    printDoublyLinkedList(sortedList);

    cout << "\n\n\n";
    sortedList = new Node {nullptr, nullptr, 0};
    sortedList = insert(sortedList, new Node {nullptr, nullptr, 1});
    printList(sortedList);
    sortedList = insert(sortedList, new Node {nullptr, nullptr, 5});
    printList(sortedList);
    sortedList = insert(sortedList, new Node {nullptr, nullptr, 4});
    printList(sortedList);
    sortedList = insert(sortedList, new Node {nullptr, nullptr, 3});
    printList(sortedList);
    sortedList = insert(sortedList, new Node {nullptr, nullptr, 7});
    printList(sortedList);
    sortedList = insert(sortedList, new Node {nullptr, nullptr, -1});
    printList(sortedList);
    
    cout << endl;
}

