#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"
using namespace std;



class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size() + num2.size(), '0');
        int sum = 0;
        int carry = 0;
        for (int i = num1.size()-1; i >= 0; i--) {
            carry = 0;
            for (int j = num2.size()-1; j >= 0; j--) {
                sum = (num1[i]-'0')*(num2[j]-'0')+res[i+j+1]-'0'+carry;
                carry = sum/10;
                res[i+j+1] = sum%10+'0';
            }
            res[i] += carry;
        }

        size_t none_zero_start = res.find_first_not_of("0");
        if (none_zero_start != string::npos) {
            return res.substr(none_zero_start);
        }
        return "0";
    }
};

int main() {
    cout << Solution().multiply("9231242141", "345345") << endl;
    cout << Solution().multiply("237", "284") << endl;
    cout << Solution().multiply("408", "5") << endl;
    cout << Solution().multiply("0", "0") << endl;
    cout << Solution().multiply("1234", "0") << endl;
    cout << Solution().multiply("418", "7") << endl;
}
