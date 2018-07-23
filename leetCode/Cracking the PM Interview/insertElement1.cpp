//
//  insertElement.cpp
//  leetCode
//
//  Created by Haag, Austin P on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include "libraries.h"

// 16.1 Given a sorted array of positive integers with an empty spot (zero) at the end, insert an element in sorted order



bool insertElement(int array[], int size, int x) {
    // checking valid input
    if (size <= 0 || array[size - 1] != 0) return false;
    
    // insert into the only open slot if only one
    else if (size == 1) {
        array[0] = x;
        return true;
    }
    
    
    // size will be our moving window
    int index = size;
    --index;
    array[index] = x;
    --index;
    while (index >= 0) {
        // keep moving the element until it is in the correct place
        if (array[index] > x) {
            swap(array[index], array[index + 1]);
            --index;
        // once the element at index is smaller than x, we don't want to keep moving x
        } else {
            break;
        }
    }
    
    return true;
}


void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << ", ";
    }
}

int main() {
    
    // missing 6
    int intArr[] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 0};
    
    insertElement(intArr, 10, 6);
    printArray(intArr, 10);
//    cout << intArr[6];
    assert(intArr[6] == 6);
}
