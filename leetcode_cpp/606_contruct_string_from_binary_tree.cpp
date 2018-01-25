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
    string tree2str(TreeNode* t) {

        if (t) {
            string s = "";
            s += to_string(t->val);
            if (t->left) {
                s += "(" + tree2str(t->left) + ")";
            }
            if (t->right) {
                if (!t->left) s += "()";
                s += "(" + tree2str(t->right) + ")";
            }

            return s;
        } else {
            return "";
        }

    }
};

int main() {

    vector<int> nodes;

    nodes = {1,2,3,4};
    cout << Solution().tree2str(TreeNode().getRoot(nodes)) << endl;

    nodes = {1,2,3,INT_MIN,4};
    cout << Solution().tree2str(TreeNode().getRoot(nodes)) << endl;

    return 0;
}
