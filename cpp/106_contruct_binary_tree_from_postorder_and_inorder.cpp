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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if (inorder.size() <= 0) return NULL;
        else if (inorder.size() == 1) return new TreeNode(inorder[0]);

        TreeNode *root = rec(inorder, 0, inorder.size(), postorder, 0, postorder.size());
        return root;
    }

private:
    TreeNode* rec(vector<int> &inorder, int inStart, int inEnd,
            vector<int> &postorder, int postStart, int postEnd) {
        if (inStart >= inEnd) {return NULL;}
        else if (inStart == inEnd - 1) {return new TreeNode(inorder[inStart]);}

        TreeNode *father = new TreeNode(postorder[postEnd-1]);

        int i = 0;
        while (inorder[inStart+i] != postorder[postEnd-1]) {i++;}

        father->left = rec(inorder, inStart, inStart+i,
                            postorder, postStart, postStart+i);
        father->right = rec(inorder, inStart+i+1, inEnd,
                            postorder, postStart+i, postEnd-1);
        return father;
    }
};

int main() {

    vector<int> postorder, inorder;

    postorder = {7,8,4,2,9,5,3,1};
    inorder = {2,7,4,8,1,5,9,3};
    cout << Solution().buildTree(inorder,postorder) << endl;



    return 0;
}
