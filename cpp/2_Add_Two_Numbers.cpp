#include<iostream>
#include <vector>
#include "utils.h"
using namespace std;



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* incNode = inc(l1,l2);
        if (incNode->val >= 10) {
            ListNode* l;
            l->val = 1;
            l->next = l1;
            l1->val -= 10;
        } else {
            return incNode;
        }
        return inc(l1, l2);
    }
    ListNode* inc(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return new ListNode(0);
        }
        incNode = inc(l1->next,l2->next);
        int incre=0;
        if (incNode->val >= 10) {
            incNode->val -= 10;
            incre = 1;
        }
        int s = l1->val + l2->val + incre;
        l1->val = s;
        return l1;
    }
};

int main() {
    ListNode
    cout << Solution()->lengthOfLongestSubstring("abcabcbb") << endl;
}
