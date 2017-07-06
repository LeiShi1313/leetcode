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
        if (head == NULL || k == 1) return head;
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode *now = head, *tail = dummy_head, *to_move, *next_to_move;
        ListNode *last = dummy_head;
        int count = 0;
        while (now) {
            count++;
            now = now->next;
            if (count == k) {
                // do reverse
                tail = last->next;
                to_move = last->next->next;
                while (to_move != now) {
                    if (to_move->next) next_to_move = to_move->next;
                    else next_to_move = NULL;
                    to_move->next = last->next;
                    last->next = to_move;
                    to_move = next_to_move;
                }
                tail->next = now;
                last = tail;
                count = 0;
            }
        }

        return dummy_head->next;

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
    v = {1,2,3};
    cout << Solution().reverseKGroup(ListNode().getNodesFromInteger(v), 3) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
