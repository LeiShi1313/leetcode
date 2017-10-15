#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class FenwickTree {
    int n;
    vector<int> sum_array;
    inline int lowbit(int x) {
        return x & -x;
    }
public:
    FenwickTree(int n) :n(n), sum_array(n + 1, 0) {}
    int sum(int x) {
        int ans = 0;
        while (x > 0) {
            ans += sum_array[x];
            x -= lowbit(x);
        }
        return ans;
    }
    void add(int x, int d) {
        while (x <= n) {
            sum_array[x] += d;
            x += lowbit(x);
        }
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.size() == 0) return 0;
        vector<long long> sum_array(nums.size() * 3, 0);
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum_array[i*3] = sum;
            sum_array[i*3+1] = sum + lower - 1;
            sum_array[i*3+2] = sum + upper;
        }
        sum_array.push_back(upper);
        sum_array.push_back(lower - 1);
        unordered_map<long long, int> index;
        sort(sum_array.begin(), sum_array.end());
        auto end = unique(sum_array.begin(), sum_array.end());
        auto it = sum_array.begin();
        for (int i = 1; it != end; i++, it++) {
            index[*it] = i;
        }
        FenwickTree tree(index.size());
        int ans = 0;
        for (int i = nums.size()-1; i>= 0; i--) {
            tree.add(index[sum], 1);
            sum -= nums[i];
            ans += tree.sum(index[upper+sum]) - tree.sum(index[lower+sum-1]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums;

    nums = {-2, 5, -1};
    cout << Solution().countRangeSum(nums, -2, 2) << endl;


    return 0;
}
