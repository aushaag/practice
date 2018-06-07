//
//  twoSum.cpp
//  leetCode
//
//  Created by Haag, Austin P on 6/7/18.
//  Copyright © 2018 Haag, Austin P. All rights reserved.
//

#include <stdio.h>

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> toReturn = {99, 99};
    
    unordered_map<int, int> numMap;
    
    for (int i = 0; i < nums.size(); ++i) {
        if (numMap.find(target - nums[i]) != numMap.end())  {
            toReturn = { i, numMap[target - nums[i]]};
            return toReturn;
        }
        numMap[nums[i]] = i;
    }
    
    return toReturn;
}

void run() {
    
}
