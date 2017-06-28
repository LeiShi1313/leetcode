//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool ret = num_map.find(val) == num_map.end();
        if (ret) {
            num_map[val] = nums.size();
            nums.push_back(val);
        }
        return ret;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool ret = num_map.find(val) != num_map.end();
        if (ret) {
            int num_back = nums.back();
            nums[num_map[val]] = num_back;
            num_map[num_back] = num_map[val];
            nums.pop_back();
            num_map.erase(val);
        }
        return ret;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    unordered_map<int, int> num_map;
    vector<int> nums;
};

int main() {
//    clock_t start = clock();
    RandomizedSet *obj = new RandomizedSet();
    cout << obj->insert(0) << endl;
    cout << obj->insert(1) << endl;
    cout << obj->insert(1) << endl;
    cout << obj->remove(0) << endl;
    cout << obj->insert(2) << endl;
    cout << obj->remove(1) << endl;
    cout << obj->getRandom() << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
