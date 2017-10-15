#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        if (k == 0) return head;
        int length = getLength(head);
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* quick = head;
        int i = (k-1) % length;
        while (i) {
            quick = quick->next;
            i--;
        }
        ListNode* slow = dummyHead;
        while (quick && quick->next) {
            quick = quick->next;
            slow = slow->next;
        }
        ListNode* newHead = slow->next;
        slow->next = NULL;
        if (head != newHead)
            quick->next = head;
        return newHead;
    }
private:
    int getLength(ListNode* head) {
        int h = 0;
        ListNode* p = head;
        do {
            h++;
            p = p->next;
        } while(p);
        return h;
    }
};

int main() {

    return 0;
}
