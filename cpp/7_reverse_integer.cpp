//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long result=0;

        while (x != 0) {
            result = result*10 + (x%10);
            x /= 10;
        }
        if (result > INT_MAX || result < INT_MIN) return 0;
        return (int)result;
    }
};
int main() {
//    clock_t start = clock();
    cout << Solution().reverse(123) << endl;
    cout << Solution().reverse(-123) << endl;
    cout << Solution().reverse(-2147483648) << endl;
    cout << Solution().reverse(-2147483648) << endl;
    cout << Solution().reverse(2147483648) << endl;
    cout << Solution().reverse(7463847412) << endl;
    cout << Solution().reverse(8463847412) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
