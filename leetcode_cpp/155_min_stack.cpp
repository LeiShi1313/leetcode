//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (x <= minVal) {
            s.push(minVal);
            minVal = x;
        }
        s.push(x);
    }

    void pop() {
        int toPop = s.top();
        if (toPop == minVal) {
            s.pop();
            minVal = s.top();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minVal;
    }

private:
    int minVal = INT_MAX;
    stack<int> s;
};

int main() {

    MinStack obj = MinStack();
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout << obj.getMin() << endl;
    obj.pop();
    cout << obj.top() << endl;
    cout << obj.getMin() << endl;

    return 0;
}
