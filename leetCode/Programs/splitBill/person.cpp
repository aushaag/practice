//
//  person.cpp
//  leetCode
//
//  Created by Haag, Austin P on 6/7/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include <stdio.h>
#include "/Users/ahaag10/Documents/Coding/leetCode/leetCode/libraries.h"


void func() {
    cout << "test";
}



class Person {
public:
    string name = "Nameless Person";
    
    // Initializers
    Person(string _name) : name(_name) {};
    
    // funcs
    double personTotal();
    void addItem(double item);
    void printPersonItems();
    void clearPersonItems();
private:
        vector<double> personItems;
};


double Person::personTotal() {
    double personTotal = 0;
    for (auto item : personItems) {
        personTotal += item;
    }
    return personTotal;
}

void Person::printPersonItems() {
    cout << "---------- " << name << "'s Items ----------\n";
    for (size_t i = 0; i < personItems.size() - 2; ++i) {
        cout << personItems[i] << " + ";
    }
    cout << personItems.back() << " = " << personTotal();
    cout << "----------------------------------------\n";
}

void Person::addItem(double item) {
    personItems.push_back(item);
}

void Person::clearPersonItems() {
    personItems.clear();
}

