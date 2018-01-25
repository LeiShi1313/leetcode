//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        long result=0;
        int y = x;

        while (y != 0) {
            result = result*10 + (y%10);
            y /= 10;
        }
        return result == x;

    }
};
int main() {
//    clock_t start = clock();
    cout << Solution().isPalindrome(123) << endl;
    cout << Solution().isPalindrome(-123) << endl;
    cout << Solution().isPalindrome(-2147483648) << endl;
    cout << Solution().isPalindrome(-2147483648) << endl;
    cout << Solution().isPalindrome(2147483648) << endl;
    cout << Solution().isPalindrome(7463847412) << endl;
    cout << Solution().isPalindrome(8463847412) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
