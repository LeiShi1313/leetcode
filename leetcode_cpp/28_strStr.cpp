//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        string::size_type m=haystack.size(), n=needle.size();
        if (n == 0) return 0;
        string::size_type i, j=0;
        vector<string::size_type> mem(n, 0);

        for (i = 1; i < haystack.size(); i++) {
            while (j > 0 && needle[j] != needle[i]) {
                j = mem[j+1];
            }
            if (needle[j] == needle[i]) {
                ++j;
            }
            mem[i] = j;
        }

        i = 0; j = 0;
        while (i < m) {
            if (haystack[i] == needle[j]) {
                ++i;++j;
            }

            if (j == n) {
                return i-j;
            } else if (haystack[i] != needle[j]) {
                if (j) {
                    j = mem[j-1];
                } else {
                    ++i;
                }
            }
        }
        return -1;
    }
};
int main() {
    clock_t start = clock();
    cout << Solution().strStr("missimspsps", "a") << endl;
    clock_t end = clock();
    cout << "Time used: " << end - start << endl;
    return 0;
}
