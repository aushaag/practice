//
//  totalSales4.cpp
//  leetCode
//
//  Created by Austin Haag on 7/20/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include "libraries.h"

// 16.4
// You are given a two-dimensional array of sales data where the first column is a product ID and the second column is the quantity. Write a function to take this list of data and return a new two-dimensional array with the total sales for each product ID.

/* Example:
 Input:
 211, 4
 262, 3
 211,5
 216,6
 
 Output:
 211,9
 262,3
 216,6
 
 The output of this method needs to be a list of prudct IDs and their total counts.
 */

vector<vector<int>> totalSales(vector<vector<int>> data) {
    unordered_map<int, int> salesMap;
    
    for (auto sale : data) {
        salesMap[sale[0]] += sale[1];
    }
    
    vector<vector<int>> salesVect;
    
    for (auto pair : salesMap) {
//        vector<int> sale = { key, salesMap[2] };
        vector<int> sale = { pair.first, pair.second};
        salesVect.push_back(sale);
    }
    return salesVect;
}

int main() {
    
    vector<vector<int>> data =
                    { {211, 4},
                      {262, 3},
                      {211, 5},
                      {216, 6} };
    vector<vector<int>> data2;
    
    vector<vector<int>> newData = totalSales(data);
    
    totalSales(data2);
    
    for (auto sale : newData) {
        cout << sale[0] << ", " << sale[1] << endl;
    }
    
    cout << endl;
}
