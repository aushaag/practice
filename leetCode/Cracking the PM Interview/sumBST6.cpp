//
//  sumBST6.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include"libraries.h"


// 16.6
// Given a binary search tree which contains integers as values, calculate the sum of all the numbers

struct Node {
    Node *left;
    Node *right;
    int datum;
};


int sum(Node *root) {
    if (root == nullptr) return 0;
    return root->datum + sum(root->left) + sum(root->right);
}

bool insert(Node *root, int datum) {
    if (!root) return false;
    if (datum < root->datum) {
        if (root->left == nullptr) root->left = new Node { nullptr, nullptr, datum};
        else return insert(root->left, datum);
    } else {
        if (root->right == nullptr) root->right = new Node { nullptr, nullptr, datum};
        else return insert(root->right, datum);
    }
    return true;
}

int main() {
    Node * BST = new Node { nullptr, nullptr, 0};
    
    insert(BST, 10);
    insert(BST, 20);
    insert(BST, 30); // 60
    insert(BST, 40);
    insert(BST, 50); // 150
    insert(BST, 60); // 210
    
    cout << sum(BST);
    
    cout << endl;
}
