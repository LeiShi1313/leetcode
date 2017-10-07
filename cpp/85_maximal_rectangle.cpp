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
    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty() || matrix[0].empty()) return 0;

        int maxArea = 0;
        vector<int> heights(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
private:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> s;
        heights.push_back(0);

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (s.empty() || heights[i] >= heights[s.top()]) {
                s.push(i);
            } else {
                while (!s.empty() && heights[i] < heights[s.top()]) {
                    int topIdx = s.top();
                    s.pop();
                    maxArea = max(maxArea, heights[topIdx] * (s.empty()? i : i-1-s.top()));
                }
                s.push(i);
            }
        }
        return maxArea;
    }

};

int main() {

    vector<vector<char>> matrix;

    matrix = {
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
    };
    cout << Solution().maximalRectangle(matrix) << endl;

    matrix = {
            {'1'},
    };
    cout << Solution().maximalRectangle(matrix) << endl;


    return 0;
}
