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
    vector<int> countSmaller(vector<int>& nums) {

        vector<int> res(nums.size(), 0);
        if (nums.size() <= 1) return res;

        Node *root = new Node(nums.back());
        for (int i = nums.size()-2; i >= 0; i--) {
            res[i] = searchAndInsert(root, nums[i]);
        }
        return res;
    }
private:
    struct Node {
        int val, cnt, smaller;
        Node *left, *right;
        Node(int v) : val(v), cnt(1), smaller(0), left(NULL), right(NULL) {}
    };
    int searchAndInsert(Node *cur, int &val) {
        if (val == cur->val) {
            cur->cnt++;
            return cur->smaller;
        } else if (val < cur->val) {
            cur->smaller++;
            if (cur->left) {
                return searchAndInsert(cur->left, val);
            } else {
                cur->left = new Node(val);
                return 0;
            }
        } else {
            if (cur->right) {
                return cur->smaller + cur->cnt + searchAndInsert(cur->right, val);
            } else {
                cur->right = new Node(val);
                return cur->cnt + cur->smaller;
            }
        }
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
