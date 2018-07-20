//
//  merge_two_lists.cpp
//  leetCode
//
//  Created by Haag, Austin P on 6/19/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include <stdio.h>
#include "libraries.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    if (!l1) return l2;
    else if (!l2) return l1;
    
    // asign head of list & shift along list to next that wasn't added
    ListNode* head;
    if (l1->val < l2->val) {
        head = new ListNode(l1->val);
        l1 = l1->next;
    } else {
        head = new ListNode(l2->val);
        l2 = l2->next;
    }
    
    ListNode* toIterate = head;
    
    // need to merge
    while (l1 && l2) {
        if (l1->val < l2->val) {
            // add l1's val and iterate
            toIterate->next = new ListNode(l1->val);
            l1 = l1->next;
            toIterate = toIterate->next;
        } else {
            // add l2's val and iterate
            toIterate->next = new ListNode(l2->val);
            l2 = l2->next;
            toIterate = toIterate->next;
        }
    }
    // now one list is empty
    while (l1 != nullptr) {
        toIterate->next = new ListNode(l1->val);
        l1 = l1->next;
        toIterate = toIterate->next;
    }
    while (l2 != nullptr) {
        toIterate->next = new ListNode(l2->val);
        l2 = l2->next;
        toIterate = toIterate->next;
    }
    
    return head;
}




void printList(ListNode* l) {
    while (l != nullptr) {
        cout << l->val << "->";
        l = l->next;
    }
    cout << "nullptr";
}

void run() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    printList(mergeTwoLists(l1, l2));
    
}

