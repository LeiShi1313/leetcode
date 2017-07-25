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
    int maxProfit(int k, vector<int>& prices) {

        int len = prices.size();
        if (len < 2) return 0;
        if (k > len/2) {
            int ret = 0;
            for (int i = 1; i < len; i++) {
                ret += max(prices[i]-prices[i-1], 0);
            }
            return ret;
        }

        vector<int> buy(k+1, INT_MIN);
        vector<int> sell(k+1, 0);

        int cur;
        for (int i = 0; i < len; i++) {
            cur = prices[i];
            for (int j = k; j > 0; j--) {
                sell[j] = max(sell[j], buy[j]+cur);
                buy[j] = max(buy[j], sell[j-1]-cur);
            }
        }
        return sell[k];
    }
};

int main() {
    vector<int> nums;

    nums = {7,1,5,3,6,4};
    cout << Solution().maxProfit(2, nums) << endl;
    cout << Solution().maxProfit(3, nums) << endl;

    return 0;
}
