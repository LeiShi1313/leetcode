#include<iostream>
#include<vector>
#include<unordered_map>
#include "utils.h"
using namespace std;


class Solution {
private:
    unordered_map<string, bool> mem;
public:
    bool canWin(string s) {
        if (mem.find(s) != mem.end()){
            return mem[s];
        }

        int len = s.length();

        for (int i = 0; i < len-1; i++) {
            if (s[i] == '+' && s[i+1] == '+') {
                string tmp = s;
                tmp[i] = '-';
                tmp[i+1] = '-';
                if (!canWin(tmp))
                    return mem[s] = true;
            }
        }
        return mem[s] = false;
    }
};

int main() {

    string s = "++++";
    cout << Solution().canWin(s) << endl;

    s = "+-++";
    cout << Solution().canWin(s) << endl;

    s = "+--+";
    cout << Solution().canWin(s) << endl;

    s = "+++++";
    cout << Solution().canWin(s) << endl;
}
