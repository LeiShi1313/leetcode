#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (!amount) return 0;
        vector<int> mem(amount+1, -1);
        for (auto& coin: coins) {
            if (coin > amount) continue;
            mem[coin] = 1;
        }
        for (int i = 1; i <= amount; i++) {
            if (mem[i] != -1) continue;
            else {
                int least = INT_MAX;
                for (int j = i-1; j >= 0; j--) {
                    if (mem[j] != -1 && mem[i-j] != -1) {
                        least = min(least, mem[j] + mem[i-j]);
                    }
                }
                mem[i] = least != INT_MAX ? least : -1;
            }
        }
        return mem[amount];
    }
};

int main() {
    vector<int> coins;
    int amount;

    coins = {1,2,5};
    amount = 11;
    cout << Solution().coinChange(coins, amount) << endl;

    coins = {2};
    amount = 3;
    cout << Solution().coinChange(coins, amount) << endl;

    coins = {INT_MAX};
    amount = 3;
    cout << Solution().coinChange(coins, amount) << endl;

    coins = {1};
    amount = 0;
    cout << Solution().coinChange(coins, amount) << endl;

    coins = {2};
    amount = 1;
    cout << Solution().coinChange(coins, amount) << endl;

    coins = {470,35,120,81,121};
    amount = 9825;
    cout << Solution().coinChange(coins, amount) << endl;


    return 0;
}
