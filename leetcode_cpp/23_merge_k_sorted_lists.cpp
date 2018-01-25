//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include "utils.h"
using namespace std;


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(0);
        ListNode *last = dummy;
        int idx;
        int count = 0;

        map<int, vector<int>> cur_val;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                cur_val[lists[i]->val].push_back(i);
                count++;
            }
        }

        while (count) {
            idx = cur_val.begin()->second.back();
            last->next = lists[idx];
            last = last->next;
            lists[idx] = lists[idx]->next;
            cur_val.begin()->second.pop_back();
            if (cur_val.begin()->second.empty()) {
                cur_val.erase(cur_val.begin());
            }
            if (last->next) {
                cur_val[last->next->val].push_back(idx);
            } else {
                count--;
            }
        }
        return dummy->next;
    }
};

int main() {
//    clock_t start = clock();
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {2,4,5};
    vector<int> v3 = {4,5,6};
    vector<ListNode*> lists;
    lists.push_back(ListNode().getNodesFromInteger(v1));
    lists.push_back(ListNode().getNodesFromInteger(v2));
    lists.push_back(ListNode().getNodesFromInteger(v3));

    cout << Solution().mergeKLists(lists) << endl;

//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
