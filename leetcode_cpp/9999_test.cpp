#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;


class Solution {
public:
    void sort(vector<char> &p) {
        vector<int> mem(256);
        int i, j;
        for (i = 0; i < p.size(); ++i) {
            mem[p[i] + 128]++;
        }
        for (i = 0, j = 0; i < 256; ++i) {
            while (mem[i]--) {
                p[j++] = i-128;
            }
        }
    }
};

int main() {
    vector<char> p= {'1', 'a', 'v', 'e', '5', '8'};
    Solution().sort(p);
    cout << p << endl;
    return 0;
}
