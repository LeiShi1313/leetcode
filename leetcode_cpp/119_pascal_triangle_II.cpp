//
// Created by Dicky Shi on 6/13/17.
//
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
    vector<int> getRow(int rowIndex) {

        vector<int> res = {1};
        if (rowIndex == 0) return res;

        for (int level = 1; level <= rowIndex; level++) {
            res.push_back(1);
            for (int j = level-1; j >= 1; j--) {
                res[j] = res[j-1] + res[j];
            }
        }

        return res;
    }
};

int main() {

    cout << Solution().getRow(0) << endl;
    cout << Solution().getRow(1) << endl;
    cout << Solution().getRow(2) << endl;
    cout << Solution().getRow(3) << endl;
    cout << Solution().getRow(4) << endl;
    return 0;
}
