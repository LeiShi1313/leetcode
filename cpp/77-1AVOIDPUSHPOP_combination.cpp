//
// Created by Dicky Shi on 6/13/17.
//
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
    vector<vector<int>> combine(int n, int k) {
        v.resize(k);
        dfs(1, n, k);
        return r;
    }

private:
    vector<vector<int> > r;
    vector<int> v;
    void dfs(int i, int n, int k) {
        while (i <= n) {
            v[v.size() - k] = i++;
            if (k > 1)
                dfs(i, n, k - 1);
            else
                r.push_back(v);
        }
    }

};

int main() {
//    clock_t start = clock();
    cout << Solution().combine(4, 2) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
