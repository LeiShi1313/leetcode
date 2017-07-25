//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int sell = 0, buy = INT_MIN;

        for (auto &price: prices) {
            sell = max(buy+price, sell);
            buy = max(sell-price, buy);
        }
        return sell;
    }
};

int main() {
    vector<int> nums;

    nums = {7,1,5,3,6,4};
    cout << Solution().maxProfit(nums) << endl;

    nums = {7,6,5,4,3,2};
    cout << Solution().maxProfit(nums) << endl;

    return 0;
}
