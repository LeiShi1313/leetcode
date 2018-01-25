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
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
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
