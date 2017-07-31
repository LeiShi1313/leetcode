//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        int keep = num.size() - k;

        for (int i = 0; i < num.size(); i++) {
            while (res.size()>0 && res.back()>num[i] && k>0){
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        res.erase(keep, string::npos);

        auto pos = res.find_first_not_of('0');
        return pos>=res.size()? "0" : res.substr(pos);
    }
};

int main() {

    cout << Solution().removeKdigits("9", 1) << endl;
    cout << Solution().removeKdigits("11311", 1) << endl;
    cout << Solution().removeKdigits("10", 2) << endl;

    return 0;
}
