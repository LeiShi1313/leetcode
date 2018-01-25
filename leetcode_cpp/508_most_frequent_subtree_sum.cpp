#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) return vector<int>{};
        unordered_map<int, int> sums;
        int count = 0;
        getSubtreeSum(root, sums, count);
        vector<int> ret;
        vector<vector<int>> bucket(count+1);
        int maxF = 0;
        for (auto& kv: sums) {
            bucket[kv.second].push_back(kv.first);
        }
        for (int i = bucket.size()-1; i >= 0; i--) {
            if (!bucket[i].empty()) {
                return bucket[i];
            }
        }
    }

private:
    int getSubtreeSum(TreeNode* root, unordered_map<int, int>& sums, int& count) {

        int sum = root->val;
        if (root->left) {
            sum += getSubtreeSum(root->left, sums, count);
        }
        if (root->right) {
            sum += getSubtreeSum(root->right, sums, count);
        }
        sums[sum]++;
        count++;
        return sum;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(-3);
    root->left = left;
    root->right = right;
    cout << Solution().findFrequentTreeSum(root) << endl;

    root = new TreeNode(5);
    left = new TreeNode(2);
    right = new TreeNode(-5);
    root->left = left;
    root->right = right;
    cout << Solution().findFrequentTreeSum(root) << endl;

    root = new TreeNode(1);
    cout << Solution().findFrequentTreeSum(root) << endl;
    return 0;
}
