//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include "utils.h"
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 1) return "1";
        string pre = "1";
        string tmp = "";
        int count = 0;
        int i,j;
        for (i = 2; i <= n; i++) {
            count = 1;
            tmp = "";
            for (j = 1; j < pre.size(); j++) {
                if (pre[j] == pre[j-1]) {
                    count++;
                } else {
                    tmp += count+'0';
                    tmp += pre[j-1];
                    count = 1;
                }
            }
            tmp += count+'0';
            tmp += pre[j-1];
            pre = tmp;
        }
        return pre;
    }
};

int main() {
    cout << Solution().countAndSay(1) << endl;
    cout << Solution().countAndSay(2) << endl;
    cout << Solution().countAndSay(3) << endl;
    cout << Solution().countAndSay(4) << endl;
    cout << Solution().countAndSay(5) << endl;
    cout << Solution().countAndSay(6) << endl;

    return 0;
}
