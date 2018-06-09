//
//  roman_to_integer.cpp
//  leetCode
//
//  Created by Haag, Austin P on 6/8/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include <stdio.h>
#include "libraries.h"

int romanToInt(string s) {
    int solution = 0;
//    deque<char> numerals;
    vector<char> numerals;
    for (auto character : s) {
        numerals.push_back(character);
    }
    
    reverse(numerals.begin(), numerals.end());
//    vector<char> vect;
//    reverse(vect);

    while (!numerals.empty()) {
        switch(numerals.back()) {
            case('I'):
                if (numerals.size() >= 2 && *(numerals.rbegin() + 1) == 'V') {
                    solution += 4;
                    numerals.pop_back();
                    numerals.pop_back();
                } else if (numerals.size() >= 2 && *(numerals.rbegin() + 1) == 'X') {
                    solution += 9;
                    numerals.pop_back();
                    numerals.pop_back();
                } else {
                    solution += 1;
                    numerals.pop_back();
                }
                break;
            case('V'):
                solution += 5;
                numerals.pop_back();
                break;
            case('X'):
                if (numerals.size() >= 2 && *(numerals.rbegin() + 1) == 'L') {
                    solution += 40;
                    numerals.pop_back();
                    numerals.pop_back();
                } else if (numerals.size() >= 2 && *(numerals.rbegin() + 1) == 'C') {
                    solution += 90;
                    numerals.pop_back();
                    numerals.pop_back();
                } else {
                    solution += 10;
                    numerals.pop_back();
                }
                break;
            case('L'):
                solution += 50;
                numerals.pop_back();
                break;
            case('C'):
                if (numerals.size() >= 2 && *(numerals.rbegin() + 1) == 'D') {
                    solution += 400;
                    numerals.pop_back();
                    numerals.pop_back();
                } else if (numerals.size() >= 2 && *(numerals.rbegin() + 1) == 'M') {
                    solution += 900;
                    numerals.pop_back();
                    numerals.pop_back();
                } else {
                    solution += 100;
                    numerals.pop_back();
                }
                break;
            case('D'):
                solution += 500;
                numerals.pop_back();
                break;
            case('M'):
                solution += 1000;
                numerals.pop_back();
                break;
            default:
                cout << "ERROR, UNRECOGNIZED NUMERAL";
                break;
        }
    }
    
    
    return solution;
}

// MARK: SEARCH STUFF

void run() {
    cout << romanToInt("IV") << endl;
    cout << romanToInt("MCMXCIV");
}
