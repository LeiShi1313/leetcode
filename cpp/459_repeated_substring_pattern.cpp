//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string::size_type m=s.size();
        if (m == 0) return 0;
        string::size_type i=1, j=0;
        vector<string::size_type> mem(m, 0);

        while (i < m) {
            if (s[i] == s[j]) {
                mem[i++] = ++j;
            } else if (j) {
                j = mem[j-1];
            } else {
                mem[i++] = 0;
            }
        }

        return mem[m-1] && mem[m-1] % (m-mem[m-1]) == 0;
    }
};
int main() {
    clock_t start = clock();
    cout << Solution().repeatedSubstringPattern("abcabcabcabc") << endl;
    clock_t end = clock();
    cout << "Time used: " << end - start << endl;
    return 0;
}
