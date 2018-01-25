#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mem.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return mem[j] - (i-1<0?0:mem[i-1]);
    }
private:
    vector<int> mem;
};

int main() {
    vector<int> nums;

    nums = {-2,0,3,-5,2,-1};
    NumArray *obj = new NumArray(nums);
    cout << obj->sumRange(1,3) << endl;
    cout << obj->sumRange(0,2) << endl;
    cout << obj->sumRange(0,5) << endl;
    cout << obj->sumRange(2,5) << endl;

    return 0;
}
