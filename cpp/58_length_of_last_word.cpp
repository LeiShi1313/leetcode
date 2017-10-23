//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int i = s.length()-1;
        int len = 0;
        while (i >= 0 && s[i] == ' ') i--;
        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }
        return len;
    }
};

int main() {

    cout << Solution().lengthOfLastWord("") << endl;
    cout << Solution().lengthOfLastWord("a") << endl;
    cout << Solution().lengthOfLastWord("a  ") << endl;
    cout << Solution().lengthOfLastWord("q a") << endl;

    return 0;
}
