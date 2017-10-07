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
    int longestValidParentheses(string s) {
        if (s.length() < 2) return false;

        vector<int> mem(s.length()+1, 0);

        int longest = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                if (i-1 >= 0) {
                    if (s[i-1] == '(') {
                        longest = max(longest, mem[i-1]+2);
                        mem[i+1] = mem[i-1]+2;
                    } else if (mem[i]) {
                        if (i-mem[i]-1>=0 && s[i-mem[i]-1] == '(') {
                            int pre = mem[i-mem[i]-1];
                            longest = max(longest, mem[i]+2+pre);
                            mem[i+1] = mem[i] + 2 + pre;
                        }
                    }
                }
            }
        }
        return longest;
    }
};

int main() {

    string s;

    s = "(()";
    cout << Solution().longestValidParentheses(s) << endl;

    s = ")()())";
    cout << Solution().longestValidParentheses(s) << endl;

    s = "()(())";
    cout << Solution().longestValidParentheses(s) << endl;

    s = "()(()";
    cout << Solution().longestValidParentheses(s) << endl;

    return 0;
}
