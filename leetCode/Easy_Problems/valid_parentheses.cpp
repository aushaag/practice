//
//  valid_parentheses.cpp
//  leetCode
//
//  Created by Haag, Austin P on 6/18/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include <stdio.h>
#include "libraries.h"

//bool isValid(string s) {
//    reverse(s.begin(), s.end());
//    deque<char> pile;
//
//
//    while (s.size() > 0) {
//        if (pile.empty()) {
//            pile.push_front(s.back());
//            s.pop_back();
//        }
//        switch (s.back()) {
//            case ('('):
//                if (pile.back() == ')') {
//                    pile.pop_back();
//                } else {
//                    pile.push_back(s.back());
//                }
//                s.pop_back();
//                break;
//            case('{'):
//                if (pile.back() == '}') {
//                    pile.pop_back();
//                } else {
//                    pile.push_back(s.back());
//                }
//                s.pop_back();
//                break;
//            case('['):
//                if (pile.back() == ']') {
//                    pile.pop_back();
//                } else {
//                    pile.push_back(s.back());
//                }
//                s.pop_back();
//                break;
//            case(')'):
//                if (pile.front() == '(') {
//                    pile.pop_front();
//                } else {
//                    pile.push_front(s.back());
//                }
//                s.pop_back();
//                break;
//
//            case('}'):
//                if (pile.front() == '{') {
//                    pile.pop_front();
//                } else {
//                    pile.push_front(s.back());
//                }
//                s.pop_back();
//                break;
//
//            case(']'):
//                if (pile.front() == '[') {
//                    pile.pop_front();
//                } else {
//                    pile.push_front(s.back());
//                }
//                s.pop_back();
//                break;
//
//        }
//    }
//    if (pile.empty()) return true;
//    else return false;
//}

bool isValid(string s) {
    if (s.size() % 2 == 1) return false;
    else if (s.size() == 0) return true;
    vector<char> pile;
    if (s[0] == ')' || s[0] == '}' || s[0] == ']') return false;
    else pile.push_back(s[0]);
    for (int i = 1; i < (int)s.size(); ++i) {
        switch (s[i]) {
            case(')'):
                if (pile.back() == '(') pile.pop_back();
                else return false;
                break;
            case('}'):
                if (pile.back() == '{') pile.pop_back();
                else return false;
                break;
            case(']'):
                if (pile.back() == '[') pile.pop_back();
                else return false;
                break;
            default:
                pile.push_back(s[i]);
        }
    }
    if (pile.empty()) return true;
    else return false;
}


void run() {
    cout << isValid("[()]");
}
