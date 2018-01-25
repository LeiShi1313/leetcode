#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> visited;
        RandomListNode* copy = new RandomListNode(head->label);
        DFS(copy, head, visited);
        return copy;
    }
private:
    void DFS(RandomListNode* copy, RandomListNode* original,
    unordered_map<RandomListNode*, RandomListNode*>& visited) {
        if (!original) return;
        else if (visited.find(original) != visited.end()) return;
        visited[original] = copy;
        RandomListNode *next = NULL, *random = NULL;
        if (original->next && visited.find(original->next) == visited.end()) {
            next = new RandomListNode(original->next->label);
        } else {
            next = visited[original->next];
        }
        if (original->random && visited.find(original->random) == visited.end()) {
            random = new RandomListNode(original->random->label);
        } else {
            random = visited[original->random];
        }
        copy->next = next;
        copy->random = random;
        DFS(copy->next, original->next, visited);
        DFS(copy->random, original->random, visited);
    }
};

int main() {

    vector<RandomListNode*> nodes;
    RandomListNode* last = NULL;
    for (int i = 0; i < 5; i++) {
        nodes.push_back(new RandomListNode(i));
        if (last) last->next = nodes[i];
        last = nodes[i];
    }
    nodes[0]->random = nodes[3];
    nodes[4]->random = nodes[2];
    nodes[2]->random = nodes[0];
    Solution().copyRandomList(nodes[0]);

    return 0;
}
