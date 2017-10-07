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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* fast= head, *slow = dummyHead;
        int count = n;
        while (fast) {
            fast = fast->next;
            if (count) count--;
            else slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};

int main() {

    vector<int> nums;

    nums = {1,2,3,4,5};
    cout << Solution().removeNthFromEnd(ListNode().getNodesFromInteger(nums), 2) << endl;

    nums = {1,2,3,4,5};
    cout << Solution().removeNthFromEnd(ListNode().getNodesFromInteger(nums), 1) << endl;
    nums = {1,2,3,4,5};
    cout << Solution().removeNthFromEnd(ListNode().getNodesFromInteger(nums), 3) << endl;
    nums = {1,2,3,4,5};
    cout << Solution().removeNthFromEnd(ListNode().getNodesFromInteger(nums), 4) << endl;
    nums = {1,2,3,4,5};
    cout << Solution().removeNthFromEnd(ListNode().getNodesFromInteger(nums), 5) << endl;
    nums = {1};
    cout << Solution().removeNthFromEnd(ListNode().getNodesFromInteger(nums), 1) << endl;

    return 0;
}
