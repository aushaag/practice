//
//  splitBill.cpp
//  leetCode
//
//  Created by Haag, Austin P on 6/7/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include <stdio.h>
#include "/Users/ahaag10/Documents/Coding/leetCode/leetCode/libraries.h"
#include "table.cpp"

void runProgram();
void run() {
    runProgram();
}

class Program {
public:
    Table table;
    
    void run();
    void collectNames();
    void collectTotals();
    void collectItems();
    void printTotals();
    void splitItem(double amount);
};

void runProgram() {
    Program toRun;
    toRun.run();
}

void Program::run() {
    cout << "Welcome to the bill sharing app, where you can share items among users!\n";
    collectNames();
    collectTotals();
    collectItems();
}

void Program::collectNames() {
    cout << "First, please indicate who shared the bill. Type a name and press enter. Once all have been added, type \"Done\".\n";
    
    string name = "";
    
    while (cin >> name && name != "done" && name != "Done" && name != "Done." && name != "done.") {
        table.addPerson(name);
    }
    
    table.printParty();
    
}

void Program::collectTotals() {
    cout << "Please enter the subtotal amount, not including tax or tip (such as 42.5):";
    cin >> table.subTotal;
    cout << "\nPlease enter the tax amount (such as 3.5):";
    cin >> table.tax;
    cout << "\nPlease enter the tip amount (such as 1.5):";
    cin >> table.tip;
    cout << "\n\n\n\n\n\n\n";
    table.printTotals();
}

void Program::collectItems() {
    double toAdd = table.subTotal;
    double item;
    cout << "We are now going to assign receipt items to each person. \nPlease enter the first item amount (such as 3.20): ";
    while (cin >> item) {
        if (toAdd - item < 0) {
            cout << "You have made a mistake since your items add to more than your subtotal. Please start over with inputting items.\n";
            toAdd = table.subTotal;
            
        } else {
            toAdd -= item;
            cout << "\n\n\n\n\n\n\nWho shared this item? Please write the person's numbers, separated by a space.\n";
            splitItem(item);
        }
        
        if (toAdd == 0) {
            cout << "\n\n\n\n\n\n\nYou have applied the items successfully!\nHere are everyone's subtotal:\n";
            table.printPersonSubtotals();
            cout << "If this looks correct, please type \"Continue\", otherwise type \"Reapply Items\"\n";
            string answer;
            cin >> answer;
            if (answer == "Continue") {
                printTotals();
                break;
            } else {
                table.resetPersonAmounts();
                toAdd = table.subTotal;
            }
        } else {
            cout << "Amount remaining to add is " << toAdd << ". Please enter another item: ";
        }
    }
}

void Program::splitItem(double amount) {
    table.printPartyNumbers();
    string stringNum;
    //flush the stream
    getline(cin, stringNum);
    // get the actual input
    getline(cin, stringNum);
    istringstream numbers(stringNum);
    vector<int> toShare;
    int num;
    // determine how many are sharing the item
    while (numbers >> num) {
        toShare.push_back(num - 1);
    }
    // apply items to the people
    for (auto personID : toShare) {
        table.party[personID].addItem(amount / toShare.size());
    }
    cout << "\n\n\n\n\n\n\n$" << round(amount / toShare.size()) << " has been added to the following people: ";
    for (auto personID : toShare) {
        cout << table.party[personID].name << " ";
    }
    cout << endl;
    for (auto personID : toShare) {
        cout << table.party[personID].name << "'s new subtotal: " << table.party[personID].personTotal() << "\n";
    }
    cout << endl;
}

void Program::printTotals() {
    cout << "\n\n\n\n\n\n\n";
    cout << "--------------------------------------------------------\n";
    cout << "Success! The program has  split the tax of " << table.tax << " and the tip of " << table.tip << " proportionally between everyone.\n";
    cout << "Here is everyone's total:\n";
    
    table.printPersonTotals();
    cout << "--------------------------------------------------------\n";
    cout << "Type anything to close the program.\n";
    string close;
    cin >> close;
}
