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
    int getMinimumDifference(TreeNode* root) {

        int m = INT_MAX;
        int pre = -1;
        inOrderTraverse(root, pre, m);
        return m;
    }

private:
    void inOrderTraverse(TreeNode *node, int &pre, int &m) {

        if (node->left) inOrderTraverse(node->left, pre, m);
        if (pre < 0) pre = node->val;
        else {
            m = min(m, abs(pre-node->val));
            pre = node->val;
        }
        if (node->right) inOrderTraverse(node->right, pre, m);
    }
};

int main() {

    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    root->right = node1;
    node1->left = node2;

    cout << Solution().getMinimumDifference(root) << endl;

    vector<TreeNode*> Tree = {
            new TreeNode(543),
            new TreeNode(384),
            new TreeNode(652),
            new TreeNode(445),
            new TreeNode(699)
    };
    Tree[0]->left = Tree[1];
    Tree[0]->right = Tree[2];
    Tree[1]->right = Tree[3];
    Tree[2]->right = Tree[4];
    cout << Solution().getMinimumDifference(Tree[0]) << endl;



    return 0;
}
