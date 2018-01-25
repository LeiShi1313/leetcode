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
	ListNode* partition(ListNode* head, int x) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* insertPos = dummyHead;
        ListNode* p = head;
        while (p) {
            if (p->val < x) {
                ListNode* toInsert = p;
                p = p->next;
                insertPos->next = toInsert;
                toInsert->next = p;
            }
        }
        return dummyHead->next;
			            
	}
};
int main() {
    vector<int> nums;

    nums = {1,4,3,2,5,2};
    cout << Solution().partition(ListNode().getNodesFromInteger(nums), 2);

    return 0;
}
