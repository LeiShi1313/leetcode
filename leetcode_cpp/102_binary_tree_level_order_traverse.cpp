//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;

        int level = 1;
        firstOrderTraverse(root, res, level);
        return res;
    }

private:
    void firstOrderTraverse(TreeNode *cur, vector<vector<int>> &res, int level) {
        if (level > res.size()) {
            vector<int> curLevel;
            res.push_back(curLevel);
        }
        res[level-1].push_back(cur->val);

        if (cur->left) {
            firstOrderTraverse(cur->left, res, level+1);
        }
        if (cur->right) {
            firstOrderTraverse(cur->right, res, level+1);
        }
    }
};

int main() {

    vector<int> nums;

    nums = {3,9,20,INT_MIN,INT_MIN,15,7};
    cout << Solution().levelOrder(TreeNode().getRoot(nums)) << endl;


    return 0;
}
