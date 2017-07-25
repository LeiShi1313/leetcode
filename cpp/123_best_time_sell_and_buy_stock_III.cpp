//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy1 = INT_MIN, buy2 = INT_MIN;
        int sell1 = 0, sell2 = 0;

        for (auto &price: prices) {
            sell2 = max(buy2+price, sell2);
            buy2 = max(sell1-price, buy2);
            sell1 = max(buy1+price, sell1);
            buy1 = max(-price, buy1);
        }
        return sell2;
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
