//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    struct watch {
        char hour;
        char min;
        watch(char h, char m) {hour=h;min=m;}
        string getTime() {return (hour<10?to_string(hour):to_string(hour/10)+to_string(hour%10))+":"+string(1,'0'+min/10)+string(1,'0'+min%10);}
    };
    void rec(vector<string> &times, unsigned short &bitmap, int i, int n) {
        if (n == 0) {
            if (bitmap % 64 <= 59 && bitmap / 64 < 12) {
                string time = watch(bitmap / 64, bitmap % 64).getTime();
                times.push_back(time);
            }
            return;
        }
        unsigned short bit = 1;
        int j = 0;
        while(j<i) {bit<<=1;++j;}
        for (j = i; j < 10; ++j) {
            bitmap |= bit;
            rec(times,bitmap, j+1, n-1);
            bitmap ^= bit;
            bit <<= 1;
        }
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> times;
        unsigned short bitmap = 0;
        rec(times, bitmap, 0, num);
        return times;
    }
};

int main() {
//    clock_t start = clock();
    cout << Solution().readBinaryWatch(1) << endl;
    cout << Solution().readBinaryWatch(2) << endl;
    cout << Solution().readBinaryWatch(3) << endl;
    cout << Solution().readBinaryWatch(4) << endl;
    cout << Solution().readBinaryWatch(5) << endl;
    cout << Solution().readBinaryWatch(8) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
