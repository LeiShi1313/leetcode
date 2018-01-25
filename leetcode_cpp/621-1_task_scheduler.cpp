#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"
using namespace std;

class Solution {
public:
    /* First find the most frequent char, for this example
     * it's 'A'. Then the sequence could be AXXAXXAXX,
     * (m[25]-1)*(n+1) represents the first 6 tasks, so the
     * job left is to find the length of the last AXX, e.g.
     * how many other task has the same length as 'A'
     */
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> m(26, 0);
        for (char &c: tasks) {
            m[c-'A']++;
        }
        sort(m.begin(), m.end());
        int i = 25;
        while (i >= 0 && m[i] == m[25]) i--;

        return max((int)tasks.size(), (m[25]-1)*(n+1)+25-i);
    }
};

int main() {
    vector<char> tasks;

    tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << Solution().leastInterval(tasks, 2) << endl;
}
