//
// Created by Dicky Shi on 6/13/17.
//

//
// Created by Dicky Shi on 6/7/17.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome (string s) {
        string::size_type first=1, last=s.size()-2;
        while (first < last) {
            if (s[first] != s[last]) {
                return false;
            }
            ++first;--last;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        vector<string::size_type> first_repeat;
        for(string::size_type i = 1; i!= s.size(); ++i) {
            if (s[i] == s[0]) {
                first_repeat.push_back(i);
            }
        }

        string::size_type longest_first_repeat=0;
        while (!first_repeat.empty()) {
            if (isPalindrome(s.substr(0, first_repeat.back()+1))) {
                longest_first_repeat = first_repeat.back();
                break;
            }
            first_repeat.pop_back();
        }

        string rest = s.substr(longest_first_repeat+1, s.size()-longest_first_repeat-1);
        reverse(rest.begin(), rest.end());

        return rest+s;
    }
};
int main() {
    cout << Solution().shortestPalindrome("aaaaaaa");
    return 0;
}
