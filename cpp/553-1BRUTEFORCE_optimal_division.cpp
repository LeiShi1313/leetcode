#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"
using namespace std;

class Solution {
    struct p {
        double min;
        string minStr;
        double max;
        string maxStr;
        p(double min, string minStr, double max, string maxStr) {
            this->min = min;
            this->minStr = minStr;
            this->max = max;
            this->maxStr = maxStr;
        }
    };
public:
    string optimalDivision(vector<int>& nums) {
        unordered_map<string, p*> m;
        p *res = rec(nums, 0, nums.size()-1, m);
        return res->maxStr;
    }
private:
    p *rec(vector<int> &nums, int start, int end, unordered_map<string, p*> &m) {
        string key = to_string(start) + " " + to_string(end);
        if (m.find(key) != m.end()) return m[key];
        if (start == end) return new p{(double)nums[start], to_string(nums[start]),
                                       (double)nums[end], to_string(nums[end])};

        p *res = new p{0, "", 0, ""};

        for (int i = start; i < end; i++) {
            p *left = rec(nums, start, i, m);
            p *right = rec(nums, i+1, end, m);

            double min = left->min / right->max;
            string minStr = left->minStr + "/" + (i + 1 == end ? right->maxStr : "(" + right->maxStr + ")");
            double max = left->max / right->min;
            string maxStr = left->maxStr + "/" + (i + 1 == end ? right->minStr : "(" + right->minStr + ")");
            
            if (res->min == 0 || res->min > min) {
                res->min = min;
                res->minStr = minStr;
            }
            if (max > res->max) {
                res->max = max;
                res->maxStr = maxStr;
            }
        }
        m[key] = res;
        return res;
    }
};

int main() {
    vector<int> nums;

    nums = {1000, 100, 10, 2};
    cout << Solution().optimalDivision(nums) << endl;
}
