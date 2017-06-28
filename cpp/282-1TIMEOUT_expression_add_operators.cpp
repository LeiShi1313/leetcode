//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
private:
    unordered_map<string, int> values;
public:
    bool isOperand(string s) {
        return s=="+" || s=="-" || s=="*";
    }
    bool isNumber(const string& s)
    {
        string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }
    long long eval(vector<string> &stack) {
        vector<string> op;
        vector<string> RPN;
        for (auto &s: stack) {
            if (isNumber(s)) {
                RPN.push_back(s);
            } else if (s == "*") {
                op.push_back(s);
            } else if (s == "+" || s == "-"){
                while (!op.empty() && isOperand(op.back())) {
                    RPN.push_back(op.back());
                    op.pop_back();
                }
                op.push_back(s);
            }
        }
        while (!op.empty()) {
            RPN.push_back(op.back());
            op.pop_back();
        }
        for (auto &s: RPN) {
            if (isNumber(s))
                op.push_back(s);
            else if (isOperand(s)){
                int num2 = stoi(op.back());
                op.pop_back();
                int num1 = stoi(op.back());
                op.pop_back();
                if (s == "+") {
                    op.push_back(to_string(num1+num2));
                }
                else if (s == "-") {
                    op.push_back(to_string(num1-num2));
                }
                else if (s == "*") {
                    op.push_back(to_string(num1*num2));
                }
                else
                    cout << s;
            }
        }
        return stoll(op.back());
    }
    void rec(vector<string> &ret, vector<string> &stack, string num, int i, int target) {
        if (i == num.size()) {
            if (eval(stack) == target) {
                string s = "";
                for (auto v: stack) {
                    s += v;
                }
                ret.push_back(s.substr(1, s.size()-1));
            }
            return;
        }
        // add a number
        if (stack.back() != "0"
            && stack.back() != "#"
            && stack.back() != "+"
                && stack.back() != "-"
                && stack.back() != "*") {
            string n = stack.back();
            stack.pop_back();
            stack.push_back(n+num[i]);
            rec(ret, stack, num, i+1, target);
            stack.pop_back();
            stack.push_back(n);
        } else if (stack.back() != "0") {
            stack.push_back(string(1, num[i]));
            rec(ret, stack, num, i+1, target);
            stack.pop_back();
        }
        //add operators
        if (!isOperand(stack.back()) && i != 0) {
            stack.push_back("+");
            rec(ret, stack, num, i, target);
            stack.pop_back();
            stack.push_back("-");
            rec(ret, stack, num, i, target);
            stack.pop_back();
            stack.push_back("*");
            rec(ret, stack, num, i, target);
            stack.pop_back();
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ret(0);
        vector<string> stack(0);
        stack.push_back("#");
        rec(ret, stack, num, 0, target);
        return ret;
    }
};

int main() {
//    clock_t start = clock();
    cout << Solution().addOperators("123",6) << endl;
    cout << Solution().addOperators("232",8) << endl;
    cout << Solution().addOperators("00",0) << endl;
    cout << Solution().addOperators("105",5) << endl;
    cout << Solution().addOperators("3456237490",9191) << endl;
    cout << Solution().addOperators("3456237490",9189) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
