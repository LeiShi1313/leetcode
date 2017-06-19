//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

class Solution {
public:

    string intToRoman(int num) {
        map<int, string> int_carry_chart = {
                {10, "Ten"},
                {100, "Hundred"},
                {1000, "Thousand"},
                {1000000, "Million"},
                {1000000000, "Billion"}
        };
        vector<string> digits = {"Zero", "One", "Two", "Three", "Four", "Five",
                                "Six", "Seven", "Eight", "Nine"};
        vector<string> tens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                               "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tyies = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty",
                                "Sixty", "Seventy", "Eighty", "Ninety"};


        int carry = 1000000000;
        int i = 0;
        int j = 0; // for number less than 1000
        string result = "";
        string tail = "";
        while (carry) {
            i = num / carry;
            if (i > 9) {
                j = i / 100;
                if (j > 0) {
                    result += digits[i/100]+" ";
                    result += "Hundred ";
                }
                j = (i%100) / 10;
                if (j > 1) {
                    result += tyies[j]+" ";
                    if (i%10) {
                        result += digits[i%10]+" ";
                    }
                } else if (j == 1) {
                    result += tens[i%10]+" ";
                } else if (i%10 > 0) {
                    result += digits[i%10]+" ";
                }
                result += int_carry_chart[carry]+" ";
            } else if (i > 0) {
                result += digits[i] + " ";
                result += int_carry_chart[carry]+" ";
            } else if (result == "" && carry == 1 && i == 0) {
                result = "Zero";
            }
            num %= carry;
            carry /= 1000;
        }
        result.erase(result.find_last_not_of(" \n\r\t")+1);
        return result;
    }
};
int main() {
//    clock_t start = clock();
    cout << Solution().intToRoman(123) << " - One Hundred Twenty Three" << endl;
    cout << Solution().intToRoman(12345) << " - Twelve Thousand Three Hundred Forty Five" << endl;
    cout << Solution().intToRoman(1234567) << " - One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven" << endl;
    cout << Solution().intToRoman(100000007) << "*" << endl;
    cout << Solution().intToRoman(0) << "*" << endl;
    cout << Solution().intToRoman(4) << "*" << endl;
    cout << Solution().intToRoman(14) << "*" << endl;
    cout << Solution().intToRoman(56) << "*" << endl;
    cout << Solution().intToRoman(30) << "*" << endl;
    cout << Solution().intToRoman(301) << "*" << endl;
    cout << Solution().intToRoman(3001) << "*" << endl;
    cout << Solution().intToRoman(1000) << "*" << endl;
    cout << Solution().intToRoman(100) << "*" << endl;
    cout << Solution().intToRoman(10) << "*" << endl;
    cout << Solution().intToRoman(INT_MAX) << "*" << endl;

//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
