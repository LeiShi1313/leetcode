//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {

        priority_queue<int> low;
        multiset<pair<int, int>> high;

        for (int i = 0; i < Profits.size(); ++i) {
            if (Profits[i] > 0)
                if (Capital[i] <= W)
                    low.push(Profits[i]);
                else
                    high.emplace(Capital[i], Profits[i]);
        }

        while (k-- && low.size()) {
            W += low.top();
            low.pop();
            for (auto it = high.begin(); high.size() && it->first <= W; it = high.erase(it)) {
                low.push(it->second);
            }
        }

        return W;
    }
};

int main() {
    vector<int> Profit;
    vector<int> Capital;

    Profit = {1,2,3};
    Capital = {0,1,1};
    cout << Solution().findMaximizedCapital(2, 0, Profit, Capital) << endl;

    return 0;
}
