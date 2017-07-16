//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if (root == NULL) return true;
        if (!root->left && !root->right) return true;

        queue<TreeNode*> q1,q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()) {
            auto left = q1.front();
            q1.pop();
            auto right = q2.front();
            q2.pop();
            if (left == NULL && right == NULL) continue;
            if (left == NULL || right == NULL) return false;
            if (left->val != right->val) return false;

            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};

int main() {

    vector<int> nums;

    nums = {1,2,2,3,4,4,3};
    cout << Solution().isSymmetric(TreeNode().getRoot(nums)) << endl;

    nums = {1,2,2,INT_MIN,3,INT_MIN,3};
    cout << Solution().isSymmetric(TreeNode().getRoot(nums)) << endl;

    return 0;
}
