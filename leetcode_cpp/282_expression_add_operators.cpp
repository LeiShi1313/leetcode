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
    void rec(vector<string> &ret, string s, string num, int index, long long last, string op, long long cur, int target) {
        if (index == num.size()) {
            if (cur == target) {
                ret.push_back(s);
            }
            return;
        }
        for (int i = index+1; i <= num.size(); ++i) {
            string num2 = num.substr(index, i-index);
            long long val = stoll(num2);
            if (to_string(val).size() != num2.size())
                continue;
            rec(ret, s+"+"+num2, num, i, val, "+", cur+val, target);
            rec(ret, s+"-"+num2, num, i, val, "-", cur-val, target);
            rec(ret, s+"*"+num2, num, i, last*val, op, (op=="+")?
                                                        (cur-last+last*val):
                                                        ((op=="-")?(cur+last-last*val):
                                                         (last*val)), target);
        }

    }
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        if (num.empty()) return ret;
        for (int i = 1; i <= num.size(); ++i) {
            string s = num.substr(0, i);
            long long cur = stoll(s);
            if (to_string(cur).size() != s.size())
                continue;
            rec(ret, s, num, i, cur, "#", cur, target);
        }
        return ret;
    }
};

int main() {
//    clock_t start = clock();
    cout << Solution().addOperators("123",6) << endl;
    cout << Solution().addOperators("232",8) << endl;
    cout << Solution().addOperators("00",0) << endl;
    cout << Solution().addOperators("105",5) << endl;
    cout << Solution().addOperators("3456237490",9191) << endl;
    cout << Solution().addOperators("3456237490",9189) << endl;
    cout << Solution().addOperators("123456789",45) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
