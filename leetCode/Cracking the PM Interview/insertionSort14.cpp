//
//  insertionSort.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include "libraries.h"


// 16.14
// Implement insertion sort.

void insertionSort(int array[], int size) {
    
    int left = 0;
    int right = 1;
    
    while (right < size) {
        left = 0;
        // find place to swap
        while (array[left] < array[right] && left != right) {
            ++left;
        }
        swap(array[left], array[right]);
        ++right;
    }
}


void printArr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    
    int A[5] = { 6, 5, 0, -1, 4};
    int sizeA = 5;
    
    int B[5] = { 0, 1, 3, 5, 7};
    int sizeB = 5;
    
    int C[0];
    int sizeC = 0;
    
    insertionSort(A, sizeA);
    printArr(A, sizeA);
    
    insertionSort(B, sizeB);
    printArr(B, sizeB);
    
    insertionSort(C, 0);
    printArr(C, sizeC);
    
    
    
    cout << endl;
}


