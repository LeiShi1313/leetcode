#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> m;
        int count = 0;
        for (auto &task: tasks) {
            m[task]++;
            count = max(count, m[task]);
        }

        int ans = (count-1)*(n+1);
        for (auto &item: m) {
            if (item.second == count) {
                ans++;
            }
        }
        return max((int)tasks.size(), ans);
    }
};

int main() {
    vector<char> tasks;

    tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << Solution().leastInterval(tasks, 2) << endl;
}
