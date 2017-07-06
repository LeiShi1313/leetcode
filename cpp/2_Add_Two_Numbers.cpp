#include<iostream>
#include <vector>
#include "utils.h"
using namespace std;


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        int incre = 0;
        int sum;
        while (l1 || l2 || incre) {
            sum = (l1?l1->val:0) + (l2?l2->val:0) + incre;
            incre = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return dummy->next;
    }

};

int main() {
    vector<int> n1, n2;

    n1 = {2,4,3};
    n2 = {5,6,4};
    cout << Solution().addTwoNumbers(ListNode().getNodesFromInteger(n1), ListNode().getNodesFromInteger(n2)) << endl;
}
