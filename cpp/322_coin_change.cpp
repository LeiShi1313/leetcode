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
        vector<int> mem(amount+1, amount+1);
        mem[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= amount && i-coins[j]>=0) {
                    mem[i] = min(mem[i], mem[i-coins[j]]+1);
                }
            }
        }
        return mem[amount] < amount+1 ? mem[amount] : -1;
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
