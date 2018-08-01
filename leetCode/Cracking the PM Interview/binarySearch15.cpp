//
//  binarySearch15.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include "libraries.h"


// 16.15
// Implement binary search. That is, given a sorted array of integers and a value, find the location of that value.

int binarySearchHelper(int arr[], int x, int left, int right) {
    if (left > right) return -1; // not found
    int middle = (left + right) / 2;
    if (x == arr[middle]) return middle;
    // x in left half
    else if (x < arr[middle]) {
        return binarySearchHelper(arr, x, left, middle - 1);
    } else {
        return binarySearchHelper(arr, x, middle + 1, right);
    }
}

int binarySearch(int arr[], int size, int x) {
    return binarySearchHelper(arr, x, 0, size - 1);
}

// iterative version

int iterativeBinarySearch(int arr[], int size, int x) {
    int right = size - 1;
    int left = 0;
    int middle;
    
    while (left <= right) {
        middle = (left + right) / 2;
        if (arr[middle] == x) return middle;
        // x in left half
        else if (x < arr[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    // not found
    return -1;
}


int main() {
    
    cout << endl;
}

