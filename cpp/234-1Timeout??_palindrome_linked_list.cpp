//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* getNodes(vector<int> &v) {
    ListNode* head=NULL;
    ListNode* next;
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        if (!head) {
            head = new ListNode(*it);
            next = head;
        } else {
            next->next = new ListNode(*it);
            next = next->next;
        }
    }
    return head;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow=head, *fast=head->next->next;
        ListNode *tmp;
        ListNode *next = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            tmp = next->next;
            next->next = slow;
            slow = next;
            next = tmp;
        }
        if (fast) {
            next = next->next;
        }
        while (next) {
            if (slow->val != next ->val) return false;
            slow = slow->next;
            next = next->next;
        }
        return true;
    }
};
int main() {
    vector<int> v = {1,2,3,4};
    cout << Solution().isPalindrome(getNodes(v)) << endl;
    v = {1,2};
    cout << Solution().isPalindrome(getNodes(v)) << endl;
    clock_t start = clock();
    v = {1,2,2,1};
    cout << Solution().isPalindrome(getNodes(v)) << endl;
    clock_t end = clock();
    cout << "Time used: " << end - start << endl;
    v = {1,2,3,2,1};
    cout << Solution().isPalindrome(getNodes(v)) << endl;
    v = {-1,2,2,-1};
    cout << Solution().isPalindrome(getNodes(v)) << endl;
    v = {1,2,1,2};
    cout << Solution().isPalindrome(getNodes(v)) << endl;
    v = {-1,2,3,2,-1};
    cout << Solution().isPalindrome(getNodes(v)) << endl;
    v = {1};
    cout << Solution().isPalindrome(getNodes(v)) << endl;
    v = {1,2,1};
    cout << Solution().isPalindrome(getNodes(v)) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
