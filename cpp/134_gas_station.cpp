#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int sum = 0;
        int maxGas = INT_MAX;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            int left = gas[i] - cost[i];
            sum += left;
            if (sum < maxGas) {
                maxGas = sum;
                start = i+1;
            }
        }
        return sum<0 ? -1 : start%gas.size();
    }
};

int main() {
    vector<int> gas;
    vector<int> cost;

    gas = {1,2,3,4,5};
    cost = {5,4,3,2,1};
    cout << Solution().canCompleteCircuit(gas, cost) << endl;

    gas = {2};
    cost = {2};
    cout << Solution().canCompleteCircuit(gas, cost) << endl;

    gas = {5};
    cost = {4};
    cout << Solution().canCompleteCircuit(gas, cost) << endl;

    gas = {67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66};
    cost = {27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    cout << Solution().canCompleteCircuit(gas, cost) << endl;

    return 0;
}
