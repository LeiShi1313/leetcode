#include<iostream>
#include <vector>
#include "utils.h"
using namespace std;


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        inc(l1, l2, 0);
        return l1;
    }
    void inc(ListNode* l1, ListNode* l2, int incre) {

        int s = l1->val + l2->val + incre;
        if (s >= 10) {
            l1->val = s-10;
            incre = 1;
        } else {
            l1->val = s;
            incre = 0;
        }

        if (l1->next == NULL && l2->next == NULL) {
            if (incre) {
                ListNode* l = new ListNode(1);
                l1->next = l;
            }
            return;
        } else if (l1->next == NULL && l2->next != NULL){
            ListNode* l = new ListNode(0);
            l1->next = l;

        } else if (l1->next != NULL && l2->next == NULL){
            ListNode* l = new ListNode(0);
            l2->next = l;
        }
        inc(l1->next, l2->next, incre);
    }
};

int main() {
    vector<int> n1, n2;

    n1 = {2,4,3};
    n2 = {5,6,4};
    cout << Solution().addTwoNumbers(ListNode().getNodesFromInteger(n1), ListNode().getNodesFromInteger(n2)) << endl;
}
