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
    bool isStrobogrammatic(string num) {
        int m = num.size();

        for (int i = 0; i < m; i++) {
            if (num[i] == '0' || num[i] == '1' || num[i] == '8') {
                if (num[m-i-1] != num[i]) return false;
            }
            else if (num[i] == '6') {
                if (m % 2 == 1 && i == m/2) return false;
                else {
                    if (num[m-i-1] != '9') return false;
                }
            } else if (num[i] == '9') {
                if (m % 2 == 1 && i == m/2) return false;
                else {
                    if (num[m-i-1] != '6') return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string num;

    num = "6";
    cout << Solution().isStrobogrammatic(num) << endl;

    num = "69";
    cout << Solution().isStrobogrammatic(num) << endl;

    num = "10";
    cout << Solution().isStrobogrammatic(num) << endl;

    num = "619";
    cout << Solution().isStrobogrammatic(num) << endl;

    num = "88";
    cout << Solution().isStrobogrammatic(num) << endl;

    return 0;
}
