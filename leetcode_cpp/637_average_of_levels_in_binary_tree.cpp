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
    // using a queue is faster than stack, just iterate the size of queue each while
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> res;
        stack<TreeNode*> s;
        s.push(root);
        double sum;
        int count;
        while (!s.empty()) {
            stack<TreeNode*> tmp;
            sum = 0;
            count = 0;
            while (!s.empty()) {
                auto node = s.top();
                s.pop();
                sum += node->val;
                count++;
                if (node->left) tmp.push(node->left);
                if (node->right) tmp.push(node->right);
            }
            res.push_back(sum / (double)count);
            s = tmp;
        }
        return res;
    }
};

int main() {

    vector<int> nums;

    nums = {3,9,20,INT_MIN,INT_MIN,15,7};
    cout << Solution().averageOfLevels(TreeNode().getRoot(nums)) << endl;

    nums = {-2,-9,0,3,5,-1,9,5,2,INT_MIN,INT_MIN,-3,INT_MIN,-7,6,-6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,-1,INT_MIN,INT_MIN,INT_MIN,-9,9};
    cout << Solution().averageOfLevels(TreeNode().getRoot(nums)) << endl;

    nums = {2147483647,2147483647,2147483647};
    cout << Solution().averageOfLevels(TreeNode().getRoot(nums)) << endl;

    return 0;
}
