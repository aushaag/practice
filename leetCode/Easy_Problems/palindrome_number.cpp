//
//  palindrome_number.cpp
//  leetCode
//
//  Created by Haag, Austin P on 6/7/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include <stdio.h>
#include "libraries.h"

bool palindrome_number(int x) {
    if (x < 0) return false;
    if (x == 10) return false;
    
    int reversedNumber = 0;
    
    while (reversedNumber < x) {
        reversedNumber = reversedNumber * 10 + x % 10;
        x /= 10;
    }
    return reversedNumber == x || reversedNumber / 10 == x;
}


void run() {
    cout << palindrome_number(10);
//    assert(palindrome_number(5));
//    assert(palindrome_number(121));
//    assert(!palindrome_number(122));
//    assert(!palindrome_number(-121));
//    assert(palindrome_number(123454321));
}
