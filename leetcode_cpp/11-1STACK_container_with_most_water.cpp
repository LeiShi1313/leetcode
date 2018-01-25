#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        vector<int> s;

        s.push_back(0);
        int maxA = 0;
        for (int i = 1; i < height.size(); i++) {
            if (height[i] >= height[s.back()]) {
                s.push_back(i);
            } else {
                for (int k = 0; k < s.size(); k++) {
                    if (height[s[k]] <= height[i]) {
                        maxA = max(maxA, (i-s[k])*height[s[k]]);
                    } else {
                        maxA = max(maxA, (i-s[k])*height[i]);
                    }
                }
            }
        }
        for (int k = 0; k < s.size()-1; k++) {
            maxA = max(maxA, (s.back()-s[k])*height[s[k]]);
        }
        return maxA;
    }
};

int main() {
    
    vector<int> height;
    
    height = {2,3,2,1,2,4,3};
    cout << Solution().maxArea(height) << endl;

    height = {2,3,2,1,2,4};
    cout << Solution().maxArea(height) << endl;

    height = {2,1};
    cout << Solution().maxArea(height) << endl;

    height = {1,3,2,5,25,24,5};
    cout << Solution().maxArea(height) << endl;

    height = {4,4,2,11,0,11,5,11,13,8};
    cout << Solution().maxArea(height) << endl;
    return 0;
}
