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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        DFS(root, node, visited);
        return root;
    }
private:
    void DFS(UndirectedGraphNode *parent, UndirectedGraphNode *original,
             unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &visited) {
        if (visited.find(original) != visited.end()) return;
        else visited[original] = parent;
        for (auto &neighbor: original->neighbors) {
            UndirectedGraphNode *node;
            if (visited.find(neighbor) != visited.end()) {
                node = visited[neighbor];
                parent->neighbors.push_back(node);
            } else {
                node = new UndirectedGraphNode(neighbor->label);
                parent->neighbors.push_back(node);
                DFS(node, neighbor, visited);
            }
        }
    }
};

int main() {
    UndirectedGraphNode *node0 = new UndirectedGraphNode(0);
    UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode *node2 = new UndirectedGraphNode(2);

    node0->neighbors.push_back(node1);
    node0->neighbors.push_back(node2);
    node1->neighbors.push_back(node0);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node0);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node2);

    Solution().cloneGraph(node0);

    return 0;
}
