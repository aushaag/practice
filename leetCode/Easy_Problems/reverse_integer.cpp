//
//  reverse_integer.cpp
//  leetcode
//
//  Created by Haag, Austin P on 6/7/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

//#include "libraries.h"
#include <iostream>
int reverse(int x) {
    
    int negative = 1;
    if (x < 0) {
        x *= -1;
        negative = -1;
    }
    // 1234 to get 4, we need x mod 10
    long solution = 0;
    while (x > 0) {
        solution += x % 10;
        solution *= 10;
        x /= 10;
    }
    if (solution / 10 > INT_MAX) {
        return 0;
    }
    int toReturn = int(solution / 10 * negative);
    return toReturn;
}


void run() {
    
    std::cout << "5 -- " << reverse(5) << endl;
    std::cout << "123 -- " << reverse(123) << endl;
    std::cout << "-123 -- " << reverse(-123) << endl;
    std::cout << "-120 -- " << reverse(-120) << endl;
}
