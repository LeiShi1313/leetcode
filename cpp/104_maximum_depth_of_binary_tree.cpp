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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int maxDep = 1;
        int cur = 1;
        postOrderTraverse(root, cur, maxDep);

        return maxDep;
    }

private:
    void postOrderTraverse(TreeNode *cur, int curDep, int &maxDep) {
        if (cur->left) {
            postOrderTraverse(cur->left, curDep+1, maxDep);
        }
        if (cur->right) {
            postOrderTraverse(cur->right, curDep+1, maxDep);
        }
        if (!cur->left && !cur->right) {
            maxDep = max(curDep, maxDep);
        }
    }
};

int main() {

    vector<int> nums;

    nums = {1,3,2,3,1};
    cout << Solution().maxDepth(TreeNode().getRoot(nums)) << endl;


    return 0;
}
