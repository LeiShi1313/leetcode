#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class FenwickTree {
    vector<int> sum_array;
    int n;
    inline int lowbit(int x) {
        return x & -x;
    }
public:
    FenwickTree(int n) : n(n), sum_array(n+1, 0) {}

    void add(int x, int val) {
        while (x <= n) {
            sum_array[x] += val;
            x += lowbit(x);
        }
    }
    int sum(int x) {
        int res = 0;
        while (x > 0) {
            res += sum_array[x];
            x -= lowbit(x);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> dict;

        for (int i = 0; i < temp.size(); i++) {
            dict[temp[i]] = i+1;
        }

        FenwickTree tree(nums.size());
        vector<int> ans(nums.size(), 0);
        for (int i = nums.size()-1; i >= 0; i--) {
            ans[i] = tree.sum(dict[nums[i]] - 1);
            tree.add(dict[nums[i]], 1);
        }
        return ans;
    }

};

int main() {
    vector<int> nums;
    vector<int> ans;

    nums = {1,1};
    ans = {0,0};
    cout << Solution().countSmaller(nums) << endl;
    cout << ans << endl << endl;

    nums = {5,2,5,1};
    ans = {2,1,1,0};
    cout << Solution().countSmaller(nums) << endl;
    cout << ans << endl << endl;

    nums = {5,2,6,1};
    ans = {2,1,1,0};
    cout << Solution().countSmaller(nums) << endl;
    cout << ans << endl << endl;

    nums = {5,4,3,2,1};
    ans = {4,3,2,1,0};
    cout << Solution().countSmaller(nums) << endl;
    cout << ans << endl << endl;

    nums = {1,2,3,4,5};
    ans = {0,0,0,0,0};
    cout << Solution().countSmaller(nums) << endl;
    cout << ans << endl << endl;

    nums = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    ans = {10,27,10,35,12,22,28,8,19,2,12,2,9,6,12,5,17,9,19,12,14,6,12,5,12,3,0,10,0,7,8,4,0,0,4,3,2,0,1,0};
    cout << Solution().countSmaller(nums) << endl;
    cout << ans << endl << endl;

    return 0;
}
