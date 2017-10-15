#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int lastDigit = b.back();
        b.pop_back();
        return modPow(superPow(a, b), 10) * modPow(a, lastDigit) % base;
    }
private:
    const int base = 1337;
    int modPow(int a, int p) {
        a %= base;
        int res = 1;
        for (int i = 0; i < p; i++) {
            res = res*a % base;
        }
        return res;
    }
};

int main() {
    vector<int> b;

    b = {1,0};
    cout << Solution().superPow(2, b) << endl;

    b = {3};
    cout << Solution().superPow(2, b) << endl;


    return 0;
}
