//
// Created by Dicky Shi on 6/17/17.
//

#include <iostream>
#include <vector>
#include "utils.h"


ListNode* ListNode::getNodesFromInteger(std::vector<int> &v) {
    ListNode* head=NULL;
    ListNode* next;
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
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

int ListNode::getVal() {
    return val;
}

std::ostream& operator <<(std::ostream& out, ListNode* l) {
    ListNode *now = l;
    while(now) {
        out << now->val << "->";
        now = now->next;
    }
    out << "NULL";
    return out;
}

std::vector<std::vector<char> > string_to_vector_of_char(std::vector<std::string> strs) {
    std::vector<std::vector<char> > chars;
    for (auto &str: strs) {
        std::vector<char> cs;
        for (auto &c: str) {
            cs.push_back(c);
        }
        chars.push_back(cs);
    }
    return chars;
}
