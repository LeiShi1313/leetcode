#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"
using namespace std;



class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() > num1.size()) return multiply(num2, num1);

        vector<string> num_to_add;
        unordered_map<int, string> products;
        string append_zeros = "";

        for (int i = num2.size()-1; i >= 0; i--) {
            if (products.find(num2[i]-'0') == products.end()) {
                int product, carry = 0;
                string num = "";
                for (int j = num1.size()-1; j >= 0; j--) {
                    product = (num1[j] - '0') * (num2[i] - '0') + carry;
                    num.insert(0, 1, product%10+'0');
                    carry = product/10;
                }
                if (carry) {
                    num.insert(0, 1, carry+'0');
                }
                num_to_add.push_back(num + append_zeros);
                products[num2[i]-'0'] = num;
            } else {
                num_to_add.push_back(products[num2[i]-'0'] + append_zeros);
            }
            append_zeros += '0';
        }
        string res = "";
        int sum = 0, carry = 0;
        vector<int> to_move;
        for (int i = 0; !num_to_add.empty(); i++) {
            to_move = {};
            for (int j = 0; j < num_to_add.size(); j++) {
                if (i < num_to_add[j].size()) {
                    sum += num_to_add[j][num_to_add[j].size() - 1 - i] - '0';
                } else {
                    to_move.push_back(j);
                }
            }
            for (int idx = to_move.size()-1; idx >= 0; idx--) {
                num_to_add.erase(num_to_add.begin()+idx);
            }
            sum += carry;
            res.insert(0, 1, sum%10+'0');
            carry = sum/10;
            sum = 0;
        }
        if (carry) {
            res.insert(0, 1, carry+'0');
        }
        while (res.size() > 1 && res[0] == '0') {
            res = res.substr(1);
        }
        return res;
    }
};

int main() {
    cout << Solution().multiply("9231242141", "345345") << endl;
    cout << Solution().multiply("237", "284") << endl;
    cout << Solution().multiply("408", "5") << endl;
    cout << Solution().multiply("0", "0") << endl;
    cout << Solution().multiply("1234", "0") << endl;
}
