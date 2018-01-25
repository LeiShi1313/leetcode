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
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> m(2);
        vector<int> c(2, 0);
        for (auto &num: nums) {
            if (num == m[0]) {
                c[0]++;
            } else if (num == m[1]) {
                c[1]++;
            } else {
                if (c[0] <= 0) {m[0] = num;c[0] = 1;}
                else if (c[1] <= 0) {m[1] = num;c[1] = 1;}
                else {
                    c[0]--;c[1]--;
                }

            }
        }
        vector<int> ret;
        c[0] = 0;c[1] = 0;
        for (auto &num: nums) {
            if (num == m[0]) c[0]++;
            else if (num == m[1]) c[1]++;
        }
        for (int i = 0; i < 2; i++) {
            if (c[i] > nums.size()/3) ret.push_back(m[i]);
        }
        return ret;
    }
};

int main() {
    vector<int> nums;

    nums = {1,1, 1, 2,2,2,3,1,5,6};
    cout << Solution().majorityElement(nums) << endl;

    nums = {1};
    cout << Solution().majorityElement(nums) << endl;

    nums = {1, 2};
    cout << Solution().majorityElement(nums) << endl;

    nums = {1, 2, 1};
    cout << Solution().majorityElement(nums) << endl;
    return 0;
}
