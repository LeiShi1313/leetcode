//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;

        bool isReverse = false;
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            stack<TreeNode*> tmp;
            vector<int> curLevel;
            while (!s.empty()) {
                auto node = s.top();
                s.pop();
                curLevel.push_back(node->val);
                if (!isReverse) {
                    if (node->left) tmp.push(node->left);
                    if (node->right) tmp.push(node->right);
                } else {
                    if (node->right) tmp.push(node->right);
                    if (node->left) tmp.push(node->left);
                }
            }
            res.push_back(curLevel);
            s = tmp;
            isReverse = !isReverse;
        }

        return res;
    }


};

int main() {

    vector<int> nums;

    nums = {3,9,20,INT_MIN,INT_MIN,15,7};
    cout << Solution().levelOrder(TreeNode().getRoot(nums)) << endl;

    nums = {-2,-9,0,3,5,-1,9,5,2,INT_MIN,INT_MIN,-3,INT_MIN,-7,6,-6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,-1,INT_MIN,INT_MIN,INT_MIN,-9,9};
    cout << Solution().levelOrder(TreeNode().getRoot(nums)) << endl;


    return 0;
}
