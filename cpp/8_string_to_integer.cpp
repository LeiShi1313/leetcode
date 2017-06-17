//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int s = str.size();
        if (s == 0) return 0;
        int first=0, last=str.size()-1;
        while (str[first]==' ') ++first;
        while (str[last]==' ' || str[last]<'0' || str[last]>'9') --last;
        if (first > last) return 0;
        bool isNeg = false;
        if (str[first] == '+') {++first;}
        else if (str[first] == '-') {isNeg = true;++first;}

        long result=0;
        while (first <= last) {
            if (str[first] < '0' || str[first] > '9') {
                break;
            }
            if (isNeg) {
                result = result*10 - (str[first]-'0');
                if (result < INT_MIN) return INT_MIN;
            } else {
                result = result*10 + (str[first]-'0');
                if (result > INT_MAX) return INT_MAX;
            }
            ++first;
        }
        return (int)result;
    }
};
int main() {
//    clock_t start = clock();
    cout << Solution().myAtoi("123") << endl;
    cout << Solution().myAtoi("2147483648") << endl;
    cout << Solution().myAtoi("2147483647") << endl;
    cout << Solution().myAtoi("-123") << endl;
    cout << Solution().myAtoi("-2147483648") << endl;
    cout << Solution().myAtoi("-2147483649") << endl;
    cout << Solution().myAtoi("    10522545459") << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
