#include<iostream>
#include <vector>
#include "utils.h"
using namespace std;


class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {

        char pre = ' ';
        vector<int> pos;
        int idx = 0;

        for (auto& c: s) {
            if (c == '+' && c == pre) {
                pos.push_back(idx);
            }
            pre = c;
            idx++;
        }

        vector<string> ret;
        for (auto p: pos) {
            string fliped = s.substr(0, p-1) + (s[p]=='+' ? "--" : "++") + s.substr(p+1);

            ret.push_back(fliped);
        }
        return ret;
    }
};

int main() {

    string s = "++++";
    cout << Solution().generatePossibleNextMoves(s) << endl;

    s = "+-++";
    cout << Solution().generatePossibleNextMoves(s) << endl;

    s = "+--+";
    cout << Solution().generatePossibleNextMoves(s) << endl;
}
