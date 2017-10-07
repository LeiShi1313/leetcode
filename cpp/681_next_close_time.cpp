#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        set<char> digits;
        for (auto &c: time) {
            if (c != ':') {
                digits.insert(c);
            }
        }
        int min = timeToNum(time);
        string str = time;
        int cur = INT_MAX;
        int global_min = INT_MAX;
        rec(digits, str, 0, min, cur, global_min);
        if (cur == INT_MAX) return numToTime(global_min);
        else return numToTime(cur);
    }
private:
    int timeToNum(string time) {
        return stoi(time.substr(0, 2))*60 + stoi(time.substr(3, 2));
    }
    string numToTime(int time) {
        int hour = time / 60;
        int min = time % 60;
        return (hour<10? "0"+to_string(hour) : to_string(hour))
               + ":"
               + (min<10? "0"+to_string(min) : to_string(min));
    }
    bool isValid(string time) {
        return stoi(time.substr(0, 2)) < 24 && stoi(time.substr(3, 2)) < 59;
    }
    void rec(set<char>& digits, string str, int i, int &min, int &cur,int &global_min) {
        if (i == 2) {
            rec(digits, str, i+1, min, cur, global_min);
            return;
        }
        if (i > 4) {
            if (isValid(str)) {
                int now = timeToNum(str);
                if (now < global_min) global_min = now;
                if (now > min && now < cur) cur = now;
            }
            return;
        }
        char original = str[i];
        for (auto &d: digits) {
            str[i] = d;
            rec(digits, str, i+1, min, cur, global_min);
        }
    }
};

int main() {

    string time;

    time = "19:34";
    cout << Solution().nextClosestTime(time) << endl;

    time = "23:59";
    cout << Solution().nextClosestTime(time) << endl;

    time = "01:32";
    cout << Solution().nextClosestTime(time) << endl;

    time = "20:48";
    cout << Solution().nextClosestTime(time) << endl;

    return 0;
}
