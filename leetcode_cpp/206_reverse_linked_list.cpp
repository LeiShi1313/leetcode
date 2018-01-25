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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *tmp, *next=head->next, *now=head;
        head->next = NULL;
        while (next) {
            tmp = next->next;
            next->next = now;
            now = next;
            next = tmp;
        }
        return now;
    }
};
int main() {
//    clock_t start = clock();
    vector<int> v = {1,2,3};
    cout << Solution().reverseList(ListNode().getNodesFromInteger(v)) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
