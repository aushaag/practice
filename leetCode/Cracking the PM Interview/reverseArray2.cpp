//
//  reverseArray.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include "libraries.h"


// 16.2
void reverse(int array[], int size) {
    int front = 0;
    int back = size - 1;
    
    // to reverse, swap the front and the back element until you get to the middle
    while (front < back) {
        swap(array[front], array[back]);
        ++front;
        --back;
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << ", ";
    }
}

int main() {
    
    // size = 0
    int arr0[] = {};
    
    // size = 1
    int arr1[] = { 0 };
    
    // size = 10
    int arr10[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // size = 9
    int arr9[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8};
    
    reverse(arr10, 10);
    printArray(arr10, 10);
    cout << endl;
    
    reverse(arr9, 9);
    printArray(arr9, 9);
    cout << endl;
    
    reverse(arr1, 1);
    printArray(arr1, 1);
    cout << endl;
    
    reverse(arr0, 0);
    printArray(arr0, 0);
    cout << endl;
    
}
