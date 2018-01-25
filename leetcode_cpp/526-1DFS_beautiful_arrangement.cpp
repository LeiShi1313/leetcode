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

    void rec(vector<int> &arr, int &count, int i, int bitmap, int N) {
        if (arr.size() == N) {
            count++;
            return;
        }
        int bit = 1,j=0;
//        while (j<i) {bit<<=1;++j;}
        for (j = 0; j < N; ++j) {
            if ((bit & bitmap) == 0 && ((j+1)%(i+1)==0||(i+1)%(j+1)==0)) {
                arr.push_back(j+1);
                bitmap |= bit;
                rec(arr, count, i+1, bitmap, N);
                arr.pop_back();
                bitmap ^= bit;
            }
            bit<<=1;
        }
    }
    int countArrangement(int N) {
        vector<int> arr;
        int count=0;
        rec(arr, count, 0, 0, N);
        return count;
    }
};

int main() {
//    clock_t start = clock();
    cout << Solution().countArrangement(2) << endl;
    cout << Solution().countArrangement(3) << endl;
    cout << Solution().countArrangement(4) << endl;
    cout << Solution().countArrangement(5) << endl;
    cout << Solution().countArrangement(11) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
