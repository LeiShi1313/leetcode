#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <ctime>
#include <algorithm>
#include <functional>
#include <numeric>
#include "utils.h"
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {

        int s = (int)costs.size();
        vector<vector<int>> minCosts(s+1, vector<int>(3, 0));

        for (int i = 0; i < s; i++) {
            // paint color 0 min cost
            minCosts[i+1][0] = min(minCosts[i][1], minCosts[i][2]) + costs[i][0];
            // paint color 1 min cost
            minCosts[i+1][1] = min(minCosts[i][0], minCosts[i][2]) + costs[i][1];
            // paint color 1 min cost
            minCosts[i+1][2] = min(minCosts[i][0], minCosts[i][1]) + costs[i][2];
        }
        return min(min(minCosts[s][0], minCosts[s][1]), minCosts[s][2]);
    }
};



int main() {

    vector<vector<int>> cost;

    cost = {
            {1,2,3},
            {3,2,1},
            {2,3,4},
            {3,4,5}
    };
    cout << Solution().minCost(cost) << endl;
    return 0;
}
