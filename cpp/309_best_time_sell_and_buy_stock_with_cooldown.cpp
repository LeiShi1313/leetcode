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
        int buy = INT_MIN, prev_buy = 0, sell = 0, prev_sell = 0;

        for (auto &price: prices) {
            prev_buy = buy;
            buy = max(prev_sell-price, buy);
            prev_sell = sell;
            sell = max(prev_buy+price, sell);
        }
        return sell;
    }
};

int main() {
    vector<int> nums;

    nums = {1,2,3,0,2};
    cout << Solution().maxProfit(nums) << endl;

    return 0;
}
