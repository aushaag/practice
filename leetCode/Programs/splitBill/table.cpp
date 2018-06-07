//
//  table.cpp
//  leetCode
//
//  Created by Haag, Austin P on 6/7/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include <stdio.h>
#include "person.cpp"


double round(double amount) {
    return floor(amount * 100) / 100;
}

class Table {
public:
    
    // vars
    vector<Person> party;
    double subTotal;
    double tax;
    double tip;
    
    // funcs
    void addPerson(string name);
    void calculateSubTotal();
    void printParty();
    void printPartyNumbers();
    void printPersonSubtotals();
    void printPersonTotals();
    void printTotals();
    void resetPersonAmounts();
};

void Table::addPerson(string name) {
    party.push_back(Person(name));
}

void Table::calculateSubTotal() {
    
    subTotal = 0;
    for (auto person : party) {
        subTotal += person.personTotal();
    }
}

void Table::printParty() {
    cout << "---------- Table Members ----------\n";
    for (auto person: party) {
        cout << person.name << " ";
    }
    cout << "\n-----------------------------------\n";
}

void Table::printPartyNumbers() {
    for (size_t i = 0; i < party.size(); ++i) {
        cout << i + 1 << ". " << party[i].name << endl;
    }
    cout << endl;
}
void Table::printTotals() {
    cout << "---------- Table Totals ----------\n";
    cout << "Subtotal: " << subTotal << "\n";
    cout << "Tax: " << tax << "\n";
    cout << "Tip: " << tip << "\n";
    cout << "Grand Total: " << subTotal + tax + tip << "\n";
    cout << "----------------------------------\n";
}

void Table::printPersonSubtotals() {
    for (auto person: party) {
        cout << person.name << "'s subtotal: " << person.personTotal() << "\n";
    }
}

void Table::resetPersonAmounts() {
    for (auto person: party) {
        person.clearPersonItems();
    }
}

void Table::printPersonTotals() {
    for (auto person : party) {
        double personPercent = person.personTotal() / subTotal;
        cout << person.name <<  ": " << round(person.personTotal() + tax * personPercent + tip * personPercent) << " (person total) = " << round(person.personTotal()) << " (subtotal) + " << round(tax * personPercent) << " (tax) + " << round(tip * personPercent) << " (tip)\n";
    }
}
