#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        int count;
        for (int i = 0; i < n; i++) {
            count = res.size();
            while (count) {
                count--;
                int curNum = res[count];
                curNum += (1 << i);
                res.push_back(curNum);
            }
        }
        return res;
    }

};

int main() {

    cout << Solution().grayCode(3) << endl;
}
