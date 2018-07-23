//
//  insertBST.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//
#include"libraries.h"
#define COUNT 10

struct Node {
    Node *left;
    Node *right;
    int datum;
};


// 16.5
// Insert an element into a binary search tree (in order). You may assume that the binary searach tree contains integers.


// NOT RECURSIVELY
bool insert(Node *&root, int datum) {
    // empty BST
    if (!root) {
        root = new Node {
            nullptr,
            nullptr,
            datum, };
        return true;
    }
    
    Node * nodePtr = root;
    while (nodePtr) {
        if (datum < nodePtr->datum) {
            if (nodePtr->left == nullptr) {
                nodePtr->left = new Node { nullptr, nullptr, datum};
                break;
            } else {
                nodePtr = nodePtr->left;
                continue;
            }
        } else {
            if (nodePtr->right == nullptr) {
                nodePtr->right = new Node { nullptr, nullptr, datum};
                break;
            } else {
                nodePtr = nodePtr->right;
                continue;
            }
        }
    }
    
    return true;
}


// RECURSIVELY

bool insertRecursive(Node *root, int datum) {
    if (!root) return false;
    if (datum < root->datum) {
        if (root->left == nullptr) root->left = new Node { nullptr, nullptr, datum};
        else return insertRecursive(root->left, datum);
    } else {
        if (root->right == nullptr) root->right = new Node { nullptr, nullptr, datum};
        else return insertRecursive(root->right, datum);
    }
    return true;
    
}

void printBST_inOrder(Node * root) {
    if (root) {
        printBST_inOrder(root->left);
        cout << root->datum << " ";
        printBST_inOrder(root->right);
    }
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
    
    // Increase distance between levels
    space += COUNT;
    
    // Process right child first
    print2DUtil(root->right, space);
    
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->datum);
    
    // Process left child
    print2DUtil(root->left, space);
}

int main() {
    
    Node * head = nullptr;
    
    insert(head, 1);
    insertRecursive(head, 2);
    insertRecursive(head, 5);
    insertRecursive(head, 3);
    insertRecursive(head, 6);
    insertRecursive(head, 10);
    insertRecursive(head, 0);
    //cout << head->datum;
    
    printBST_inOrder(head);
    print2DUtil(head, 0);
    
    cout << endl;
}
