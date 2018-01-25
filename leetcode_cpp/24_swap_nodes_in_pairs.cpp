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

    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode *now = head, *next;
        ListNode *last = dummy_head;
        int count = 0;
        while (now && now->next) {
            next = now->next->next;
            last->next = now->next;
            last->next->next = now;
            now->next = next;
            last = now;
            now = next;
        }

        return dummy_head->next;

    }
};

int main() {
//    clock_t start = clock();
    vector<int> v;
    v = {1,2,3,4,5};
    cout << Solution().swapPairs(ListNode().getNodesFromInteger(v)) << endl;
    v = {1};
    cout << Solution().swapPairs(ListNode().getNodesFromInteger(v)) << endl;
    v = {1,2,3};
    cout << Solution().swapPairs(ListNode().getNodesFromInteger(v)) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
