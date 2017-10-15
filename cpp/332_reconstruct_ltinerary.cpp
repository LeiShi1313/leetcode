#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        if (tickets.size() == 0) return res;
        unordered_map<string, multiset<string>> graph;
        for (auto& ticket: tickets) {
            graph[ticket.first].insert(ticket.second);
        }
        stack<string> s;
        s.push("JFK");
        while(!s.empty()) {
            string last = s.top();
            if (graph[last].empty()) {
                res.push_back(last);
                s.pop();
            } else {
                s.push(*graph[last].begin());
                graph[last].erase(graph[last].begin());
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {

    vector<pair<string, string>>  tickets;

    tickets = {
            {"JFK", "SFO"},
            {"JFK", "ATL"},
            {"SFO", "ATL"},
            {"ATL", "JFK"},
            {"ATL", "SFO"}
    };
    cout << Solution().findItinerary(tickets) << endl;

    tickets = {
            {"JFK", "KUL"},
            {"JFK", "NRT"},
            {"NRT", "JFK"},
    };
    cout << Solution().findItinerary(tickets) << endl;
    return 0;
}
