//
//  add_two_numbers.cpp
//  leetCode
//
//  Created by Haag, Austin P on 6/12/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include <stdio.h>
#include "libraries.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* node = head;
    bool add1 = false;
    int val = 0;
    
    while(l1 != nullptr || l2 != nullptr || add1) {
        val += l1 ? l1->val : 0;
        val += l2 ? l2->val : 0;
        if (add1) {
            val += 1;
            add1 = false;
        }
        if (val >= 10) {
            add1 = true;
            val -= 10;
        }
        node->next = new ListNode(val);
        node = node->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
        val = 0;
    }
    return head->next;
}





// this solution only works up to a certain size and is very inelegant
long long convertToInt(ListNode* node) {
    long long number = 0;
    long long multiplier = 1;
    
    while (node != nullptr) {
        number += node->val * multiplier;
        multiplier *= 10;
        node = node->next;
    }
    return number;
}


ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
    long long solution = convertToInt(l1) + convertToInt(l2);
    
    auto toReturn = new ListNode(solution % 10);
    auto prevRef = toReturn;
    solution /= 10;
    while (solution != 0) {
        auto toAdd = new ListNode(solution % 10);
        prevRef->next = toAdd;
        prevRef = toAdd;
        solution /= 10;
    }
    return toReturn;
}

void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val;
        if (node->next != nullptr) {
            cout << " -> ";
        }
        node = node->next;
    }
}

void run() {
    
    auto n1 = ListNode(2);
    auto n2 = ListNode(4);
    n1.next = &n2;
    auto n3 = ListNode(3);
    n2.next = &n3;
    
    auto nn1 = ListNode(5);
    auto nn2 = ListNode(6);
    nn1.next = &nn2;
    auto nn3 = ListNode(4);
    nn2.next = &nn3;
    
    printList(addTwoNumbers(&n1, &nn1));
    
}
