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
    struct TreeNode {
        int val, smaller;
        TreeNode *left, *right;
        TreeNode(int val, int smaller) : val(val), smaller(smaller), left(NULL), right(NULL) {}
    };
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        function<int(TreeNode*&, int)> insert = [&](TreeNode*& root, int key){
            return !root ?
                   root = new TreeNode(key, 0), 0
                         : root->val>key ?
                           ++root->smaller,insert(root->left, key)
                                         : insert(root->right, key)+root->smaller+(root->val!=key);
        };
        TreeNode *root = NULL;
        for (int i = nums.size() - 1; i >= 0; --i)
            res[i] = insert(root, nums[i]);
        return res;
    }

};

int main() {
    vector<int> nums;
    vector<int> ans;

    nums = {1,1};
    ans = {0,0};
    cout << Solution().countSmaller(nums) << endl;
    cout << ans << endl << endl;

    nums = {2,1,1,1,1,1};
    ans = {5,0,0,0,0,0};
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
