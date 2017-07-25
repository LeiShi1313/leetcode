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

        int buy_price = INT_MAX, sell_price = 0, maxProfit = 0;
        for (auto &price: prices) {
            if (price < buy_price) {
                buy_price = price;
                sell_price = 0;
            }
            if (price > sell_price) {
                sell_price = price;
                maxProfit = max(maxProfit, sell_price - buy_price);
            }
        }
        return maxProfit;
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
