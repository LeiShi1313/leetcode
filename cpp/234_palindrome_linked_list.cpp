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
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};
int main() {
//    clock_t start = clock();
    vector<int> v = {1,2,3,4};
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
