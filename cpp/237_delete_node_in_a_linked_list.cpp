#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next = node->next;
        ListNode *now = node;
        while (next) {
            now->val = next->val;
            if (next->next) {
                next = next->next;
                now = now->next;
            } else {
                now->next = NULL;
                break;
            }
        }
    }
};

int main() {
    vector<int> nums;

    nums = {0,1,2,3,4,5,6,7};
    vector<ListNode*> nodes;
    for (auto &i: nums) {
        nodes.push_back(new ListNode(i));
        if (i) nodes[i-1]->next = nodes[i];
    }
    Solution().deleteNode(nodes[3]);
    cout << nodes[0] << endl;

    Solution().deleteNode(nodes[0]);
    cout << nodes[0] << endl;
    return 0;
}
