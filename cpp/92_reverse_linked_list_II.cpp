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
    ListNode* reverseList(ListNode* head, int m, int n) {
        if (!head || !head->next || m==n) return head;
        ListNode *tmp, *next=head->next, *now=head, *sub_head=NULL;
        int now_pos = 1;
        while (now_pos <= n) {
            if (now_pos < m-1) {
                tmp = next->next;
            } else if (now_pos == m-1) {
                sub_head = now;
                tmp = next->next;
            } else if (now_pos >= m && now_pos < n) {
                tmp = next->next;
                next->next = now;
            } else if (now_pos == n) {
                if (sub_head) {
                    sub_head->next->next = next;
                    sub_head->next = now;
                    now = head;
                } else {
                    head->next = next;
                }
                break;
            }
            now = next;
            next = tmp;
            ++now_pos;
        }
        return now;
    }
};
int main() {
//    clock_t start = clock();
    vector<int> v = {1,2,3,4,5,6};
    cout << Solution().reverseList(ListNode().getNodesFromInteger(v),2,4) << endl;
    v = {1,2,3,4,5,6};
    cout << Solution().reverseList(ListNode().getNodesFromInteger(v),1,4) << endl;
    v = {3,5};
    cout << Solution().reverseList(ListNode().getNodesFromInteger(v),1,2) << endl;
    v = {1,2,3,4,5};
    cout << Solution().reverseList(ListNode().getNodesFromInteger(v),3,4) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
