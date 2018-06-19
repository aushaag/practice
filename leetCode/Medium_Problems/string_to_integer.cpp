//
//  string_to_integer.cpp
//  leetCode
//
//  Created by Haag, Austin P on 6/18/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include <stdio.h>
#include "libraries.h"


int myAtoi(string str) {
    bool firstFound = false;
    bool negative = false;
    long solution = 0;
    int end = 0;
    bool endFound = false;
    for (int i = (int)str.size() - 1; i >= 0; --i) {
        switch(str[i]) {
            case('1'):
            case('2'):
            case('3'):
            case('4'):
            case('5'):
            case('6'):
            case('7'):
            case('8'):
            case('9'):
            case('0'):
                if (!endFound)
                end = i;
                endFound = true;
                break;
            default:
                endFound = false;
        }
    }
    bool positiveFound = false;
    bool negativeFound = false;
    for (int i = 0; i <= end; ++i) {
        switch(str[i]) {
            case '1':
                if (!firstFound) {
                    firstFound = true;
                    if (end - i > 11) {
                        return INT_MAX;
                    }
                } else firstFound = true;
                solution += 1 * (pow(10, int(end - i)));
                break;
            case '2':
                if (!firstFound) {
                    firstFound = true;
                    if (end - i > 11) {
                        return INT_MAX;
                    }
                } else firstFound = true;
                solution += 2 * (pow(10, int(end - i)));
                break;
            case '3':
                if (!firstFound) {
                    firstFound = true;
                    if (end - i > 11) {
                        return INT_MAX;
                    }
                } else firstFound = true;
                solution += 3 * (pow(10, int(end - i)));
                break;
            case '4':
                if (!firstFound) {
                    firstFound = true;
                    if (end - i > 11) {
                        return INT_MAX;
                    }
                } else firstFound = true;
                solution += 4 * (pow(10, (end - i)));
                break;
            case '5':
                if (!firstFound) {
                    firstFound = true;
                    if (end - i > 11) {
                        return INT_MAX;
                    }
                } else firstFound = true;
                solution += 5 * (pow(10, (end - i)));
                break;
            case '6':
                if (!firstFound) {
                    firstFound = true;
                    if (end - i > 11) {
                        return INT_MAX;
                    }
                } else firstFound = true;
                solution += 6 * (pow(10, (end - i)));
                break;
            case '7':
                if (!firstFound) {
                    firstFound = true;
                    if (end - i > 11) {
                        return INT_MAX;
                    }
                } else firstFound = true;
                solution += 7 * (pow(10, (end - i)));
                break;
            case '8':
                if (!firstFound) {
                    firstFound = true;
                    if (end - i > 11) {
                        return INT_MAX;
                    }
                } else firstFound = true;
                solution += 8 * (pow(10, (end - i)));
                break;
            case '9':
                if (!firstFound) {
                    firstFound = true;
                    if (end - i > 11) {
                        return INT_MAX;
                    }
                } else firstFound = true;
                solution += 9 * (pow(10, (end - i)));
                break;
            case '.':
                if (!firstFound) {
                    return 0;
                }
                break;
            case '0':
                continue;
            case ' ':
                if (firstFound || positiveFound || negativeFound) return 0;
                else break;
            case '-':
                if (positiveFound) return 0;
                negativeFound = true;
                if (firstFound) return 0;
                else {
                    negative = true;
                    if (str.size() == 1) return false;
                }
                break;
            case '+':
                if (negativeFound) return 0;
                positiveFound = true;
                continue;
            default:
                if (!firstFound) return 0;
                else continue;
        }
    }
    int negate = negative ? -1 : 1;
    if (solution > (long)INT_MAX) return negative ? INT_MIN : INT_MAX;
    else return ((int)solution * negate);
}


void run() {
    cout << myAtoi(" +1.11.2");
}
