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
        int mem[100][100][100] = {0};

        return DFS(boxes, mem, 0, boxes.size()-1, 0);
    }

private:
    int DFS(vector<int> &boxes, int mem[100][100][100], int start, int end, int k) {
        if (start > end) return 0;
        if (mem[start][end][k] != 0) return mem[start][end][k];

        while (end > start && boxes[end] == boxes[end-1]) {end--;k++;}
        mem[start][end][k] = DFS(boxes, mem, start, end-1, 0) + (k+1)*(k+1);
        for (int i = start; i < end; i++) {
            if (boxes[i] == boxes[end]) {
                mem[start][end][k] = max(mem[start][end][k],
                                         DFS(boxes,mem,start,i,k+1) + DFS(boxes,mem,i+1,end-1,0));
            }
        }
        return mem[start][end][k];
    }
};

int main() {
    vector<int> nums;

    nums = {1,3,2,2,2,3,4,3,1};
    cout << Solution().removeBoxes(nums) << endl;


    return 0;
}
