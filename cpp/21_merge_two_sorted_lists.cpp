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
        ListNode l3(INT_MIN);
        ListNode *p = &l3;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1?l1:l2;

        return l3.next;
    }
};

int main() {
//    clock_t start = clock();
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {2,4,5};
    cout << Solution().mergeTwoLists(ListNode().getNodesFromInteger(v1), ListNode().getNodesFromInteger(v2)) << endl;

//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
