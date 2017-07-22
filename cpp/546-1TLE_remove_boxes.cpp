//
// Created by Dicky Shi on 6/13/17.
//
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
    int removeBoxes(vector<int>& boxes) {
        int maxPoint = INT_MIN;

        BFS(boxes, maxPoint, 0);

        return maxPoint;
    }

private:
    void BFS(vector<int> boxes, int &maxPoint, int curPoint) {
        if (boxes.empty()) {
            maxPoint = max(maxPoint, curPoint);
            return;
        } else if (boxes.size() == 1) {
            maxPoint = max(maxPoint, curPoint+1);
            return;
        }
        int i, j;
        for (i = 0, j = 1; i < boxes.size(); ) {
            while (i+j < boxes.size() && boxes[i] == boxes[i+j]) j++;
            vector<int> _boxes(boxes.size()-j, 0);
            copy(boxes.begin(), boxes.begin()+i, _boxes.begin());
            copy(boxes.begin()+i+j, boxes.end(), _boxes.begin()+i);
            BFS(_boxes, maxPoint, curPoint+j*j);
            i += j;
            j = 1;
        }
    }
};

int main() {
    vector<int> nums;

    nums = {1,3,2,2,2,3,4,3,1};
    cout << Solution().removeBoxes(nums) << endl;


    return 0;
}
