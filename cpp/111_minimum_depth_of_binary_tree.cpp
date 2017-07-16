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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int minDep = INT_MAX;
        int cur = 1;
        postOrderTraverse(root, cur, minDep);

        return minDep;
    }

private:
    void postOrderTraverse(TreeNode *cur, int curDep, int &minDep) {
        if (cur->left) {
            postOrderTraverse(cur->left, curDep+1, minDep);
        }
        if (cur->right) {
            postOrderTraverse(cur->right, curDep+1, minDep);
        }
        if (!cur->left && !cur->right) {
            minDep = min(curDep, minDep);
        }
    }
};

int main() {

    vector<int> nums;

    nums = {1,3,2,3,1};
    cout << Solution().minDepth(TreeNode().getRoot(nums)) << endl;


    return 0;
}
