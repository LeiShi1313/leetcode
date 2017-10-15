#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int maxA(int N) {
        vector<int> prev(N, 0);
        for (int i = 0; i < 6; i++) {
            prev[i] = i+1;
        }
        for (int i = 6; i < N; i++) {
            prev[i] = max(max(2*prev[i-3], 3*prev[i-4]), 4*prev[i-5]);
        }
        return prev[N-1];
    }
};

int main() {

    cout << Solution().maxA(3) << endl;
    cout << Solution().maxA(4) << endl;
    cout << Solution().maxA(7) << endl;
    cout << Solution().maxA(8) << endl;
    cout << Solution().maxA(9) << endl;
    cout << Solution().maxA(10) << endl;
    cout << Solution().maxA(11) << endl;
    cout << Solution().maxA(12) << endl;


    return 0;
}
