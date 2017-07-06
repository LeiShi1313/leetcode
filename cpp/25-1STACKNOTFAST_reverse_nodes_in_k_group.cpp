//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
#include "utils.h"
using namespace std;


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *dummy_head = new ListNode(0);
        ListNode *now = head;
        ListNode *last = dummy_head, *tmp;
        int count = 0;
        stack<ListNode*> s;
        while (now) {
            s.push(now);
            count++;
            now = now->next;
            if (count == k) {
                // do reverse
                last->next = doReverse(s, tmp);
                count = 0;
                last = tmp;
            }
        }
        while (!s.empty()) {
            last->next = s.top();
            s.pop();
        }
        return dummy_head->next;

    }
    ListNode* doReverse(stack<ListNode*> &s, ListNode *&last) {
        ListNode* head = s.top();
        while (!s.empty()) {
            last = s.top();
            s.pop();
            if (!s.empty()) {
                last->next = s.top();
            } else {
                last->next = NULL;
            }
        }
        return head;
    }

};

int main() {
//    clock_t start = clock();
    vector<int> v;
    v = {1,2,3,4,5};
    cout << Solution().reverseKGroup(ListNode().getNodesFromInteger(v), 2) << endl;
    v = {1,2,3,4,5};
    cout << Solution().reverseKGroup(ListNode().getNodesFromInteger(v), 3) << endl;
    v = {1,2,3,4,5};
    cout << Solution().reverseKGroup(ListNode().getNodesFromInteger(v), 1) << endl;
    v = {1};
    cout << Solution().reverseKGroup(ListNode().getNodesFromInteger(v), 2) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
