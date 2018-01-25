#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        vector<vector<int>> mem(triangle.size());
        mem[0].push_back(triangle[0][0]);

        int minSum = mem[0][0];
        for (int row = 1; row < triangle.size(); row++) {
            int m = INT_MAX;
            for (int i = 0; i <= row; i++) {
                mem[row].push_back(min(i-1>=0?mem[row-1][i-1]:INT_MAX,
                                  i<=row-1?mem[row-1][i]:INT_MAX) + triangle[row][i]);
                m = min(m, mem[row][i]);
            }
            minSum = m;
        }
        return minSum;
    }
};

int main() {
    vector<vector<int>> triangle;


    triangle = {
            {2},
            {3,4},
            {6,5,7},
            {4,1,8,3}
    };
    cout << Solution().minimumTotal(triangle) << endl;
    return 0;
}
