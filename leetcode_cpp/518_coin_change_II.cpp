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
    int change(int amount, vector<int> &coins) {
        vector<int> mem(amount+1, 0);
        mem[0] = 1;
        for (auto& coin: coins) {
            for (int i = coin; i <= amount; i++) {
                mem[i] += mem[i-coin];
            }
        }

        return mem[amount];
    }
};


int main() {
    vector<int> coins;

    coins = {1,2,5};
    cout << Solution().change(5, coins) << endl;


    return 0;
}
