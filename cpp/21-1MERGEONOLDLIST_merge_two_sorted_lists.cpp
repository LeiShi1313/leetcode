//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <ctime>
#include "utils.h"
using namespace std;


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *l1_p=l1,*l2_p=l2;
        ListNode *dummy = new ListNode(0);
        ListNode *last = dummy;
        while (l1_p && l2_p) {
            if (l1_p->val < l2_p->val) {
                last->next = l1_p;
                last = l1_p;
                l1_p = l1_p->next;
            } else {
                last->next = l2_p;
                l2_p = l2_p->next;
                last->next->next = l1_p;
                last = last->next;
            }
        }

        last->next = l1_p?l1_p:l2_p;

        return dummy->next;
    }
};

int main() {
//    clock_t start = clock();
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {2,4,5};
    cout << Solution().mergeTwoLists(ListNode().getNodesFromInteger(v1), ListNode().getNodesFromInteger(v2)) << endl;


    v1 = {2};
    v2 = {1};
    cout << Solution().mergeTwoLists(ListNode().getNodesFromInteger(v1), ListNode().getNodesFromInteger(v2)) << endl;

    v1 = {-10, -10, -9, -4, 1, 6, 6};
    v2 = {-7};
    cout << Solution().mergeTwoLists(ListNode().getNodesFromInteger(v1), ListNode().getNodesFromInteger(v2)) << endl;

//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
