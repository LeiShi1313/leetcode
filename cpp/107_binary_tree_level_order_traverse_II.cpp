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

        vector<TreeNode*> s;
        s.push_back(NULL);
        s.push_back(root);
        s.push_back(NULL);
        while (!s.empty()) {
            int back = s.size()-1;

            if (s[back] == NULL) {
                back--;
                int count = 0;
                while (s[back] != NULL) {
                    if (s[back]->left) {s.push_back(s[back]->left);count++;}
                    if (s[back]->right) {s.push_back(s[back]->right);count++;}
                    back--;
                }
                if (count) s.push_back(NULL);
                else s.pop_back();
            } else {
                vector<int> curLevel;
                while (s[back] != NULL) {
                    curLevel.push_back(s[back]->val);
                    s.pop_back();
                    back = s.size() - 1;
                }
                reverse(curLevel.begin(), curLevel.end());
                res.push_back(curLevel);
                s.pop_back();
            }
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
