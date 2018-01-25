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
    int countArrangement(int N) {
        vector<int> arr;
        for (int i = 0; i < N; i++) { arr.push_back(i + 1); }
        return counts(arr, N);
    }

    int counts(vector<int> &arr, int n) {
        if (n == 0) return 1;
        int count=0;
        for (int j=0; j<n; j++) {
            if (arr[j]%n==0 || n%arr[j]==0) {
                swap(arr[j], arr[n-1]);
                count += counts(arr, n-1);
                swap(arr[j], arr[n-1]);
            }
        }
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
