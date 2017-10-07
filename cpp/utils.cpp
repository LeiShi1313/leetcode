//
// Created by Dicky Shi on 6/17/17.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include "utils.h"
#include <math.h>


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

TreeNode* TreeNode::getRoot(std::vector<int> &nums) {

    std::vector<TreeNode*> Tree(nums.size(), NULL);
    int level = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > pow(2, level)-1) {
            level++;
        }
        if (nums[i] != INT_MIN) {
            Tree[i] = new TreeNode(nums[i]);
            Tree[i]->val = nums[i];
            if (i == 0) {
                continue;
            } else if (i % 2 == 0) {
                Tree[i/2-1]->right = Tree[i];
            } else {
                Tree[(i+1)/2-1]->left = Tree[i];
            }

        }
    }
    return Tree[0];
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
std::ostream& operator <<(std::ostream& out, Interval i) {
    out << '[' << i.start << ',' << i.end << ']';
    return out;
}

void inorder(std::ostream& out, TreeNode* p, int indent=0)
{
    if(p != NULL) {
        if (indent) {
            out << std::setw(indent) << ' ';
        }
        if(p->left) inorder(out, p->left, indent+4);
        if(p->right) inorder(out, p->right, indent+4);
        out<< p->val << "\n ";
    }
}

std::ostream& operator <<(std::ostream& out, TreeNode* node) {
    inorder(out, node);
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
