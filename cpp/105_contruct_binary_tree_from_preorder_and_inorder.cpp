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
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if (preorder.size() <= 0) return NULL;
        else if (preorder.size() == 1) return new TreeNode(preorder[0]);

        TreeNode *root = rec(preorder, 0, preorder.size(), inorder, 0, inorder.size());

        return root;
    }

private:
    TreeNode* rec(vector<int> &preorder, int preStart, int preEnd,
    vector<int> &inorder, int inStart, int inEnd) {
        if (preStart >= preEnd || inStart >= inEnd) {return NULL;}
        else if (preStart == preEnd - 1 || inStart == inEnd - 1) {return new TreeNode(preorder[preStart]);}
        TreeNode *father = new TreeNode(preorder[preStart]);

        int i = 0;
        while (inorder[inStart+i] != preorder[preStart] && i < inEnd) {i++;}

        father->left = rec(preorder, preStart+1, preStart+i+1, inorder, inStart, inStart+i);
        father->right = rec(preorder, preStart+i+1, preEnd, inorder, inStart+i+1, inEnd);
        return father;
    }
};

int main() {

    vector<int> preorder, inorder;

    preorder = {1,2,4,7,8,3,5,9};
    inorder = {2,7,4,8,1,5,9,3};
    cout << Solution().buildTree(preorder, inorder) << endl;

    preorder = {1,2,4,5,3,6,7};
    inorder = {4,2,5,1,6,3,7};
    cout << Solution().buildTree(preorder, inorder) << endl;


    return 0;
}
