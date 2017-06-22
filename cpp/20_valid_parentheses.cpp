//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Solution {
public:
    bool isLeft(char c) {
        return c=='{' || c=='[' || c=='(';
    }
    bool isRight(char c) {
        return c=='}' || c==']' || c==')';
    }
    bool isPair(char c1, char c2) {
        return (c1=='{' && c2=='}')
            || (c1=='[' && c2==']')
               || (c1=='(' && c2==')');
    }
    bool isValid(string s) {
        vector<char> stack;
        stack.push_back('#');

        for (int i = 0; i < s.size(); ++i) {
            if (stack.back()=='#' || isLeft(stack.back())) {
                if (isLeft(s[i])) {
                    stack.push_back(s[i]);
                } else if (isPair(stack.back(), s[i])) {
                    stack.pop_back();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return stack.back()=='#';
    }
};

int main() {
    cout << Solution().isValid("{}[]()") << endl;
    cout << Solution().isValid("{[(())]}") << endl;
    cout << Solution().isValid("{[([(({[[[") << endl;
    cout << Solution().isValid("}}]]))") << endl;
    cout << Solution().isValid("{}}]]))") << endl;
    cout << Solution().isValid("[{{}}]]))") << endl;

    return 0;
}
