//
//  mergeSort13.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include "libraries.h"

// REVIEW!

// 16.13
// Given two sorted arrays, write a function to merge them in sorted order into a new array.
// if creating an array in a function, don't return it. Need to make a new one.

int *mergeIntoNew(int A[], int sizeA, int B[], int sizeB) {
    int *C = new int[sizeA + sizeB];
    int a = 0;
    int b = 0;
    int c = 0;
    while (a < sizeA && b < sizeB) {
        C[c] = min(A[a], B[b]);
        // increment whichever was bigger
        A[a] < B[b] ? ++a : ++b;
        ++c;
    }
    // REVIEW! My temptation was to compare sizes, but I should just see how many are left to add for each
    while (a < sizeA) {
        C[c] = A[a];
        ++a;
        ++c;
    }
    while (b < sizeB) {
        C[c] = B[b];
        ++b;
        ++c;
    }
    return C;
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[5] = { 0, 1, 2, 3, 4};
    int sizeA = 5;
    
    int B[5] = { 0, 1, 2, 3, 4};
    int sizeB = 5;
    
    printArr(mergeIntoNew(A, sizeA, B, sizeB), 10);
    
    int C[5] = { 0, 1, 3, 3, 7};
    int sizeC = 5;
    
    int D[7] = { -1, 1, 4, 4, 4, 5, 6};
    int sizeD = 7;
    
    printArr(mergeIntoNew(C, sizeC, D, sizeD), 12);
    
    cout << endl;
}



