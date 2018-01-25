//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int count = 0, len = 0;
        while (senate.size() != len) {
            string s;
            len = senate.size();
            for (int i = 0; i < len; i++) {
                if (senate[i] == 'R') {
                    if (count++ >= 0) s += 'R';
                } else if (senate[i] == 'D') {
                    if (count-- <= 0) s += 'D';
                }
            }
            swap(s, senate);
        }
        if (senate[0] == 'R')
            return "Radiant";
        else
            return "Dire";
    }
};

int main() {

    cout << Solution().predictPartyVictory("RDD") << endl;
    cout << Solution().predictPartyVictory("RD") << endl;
    cout << Solution().predictPartyVictory("DR") << endl;
    cout << Solution().predictPartyVictory("RDDRD") << endl;
    return 0;
}
