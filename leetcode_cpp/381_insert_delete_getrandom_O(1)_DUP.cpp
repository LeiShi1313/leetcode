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

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand((unsigned)time(NULL));
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret = false;
        if (num_map[val].empty()) {
            vector<int> n;
            num_map[val] = n;
            ret = true;
        }
        num_map[val].push_back(nums.size());
        nums.push_back(val);
        return ret;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (num_map[val].empty()) {
            return false;
        } else {
            int idx = num_map[val].back();
            if (idx != nums.size() -1) {
                int num_back = nums.back();
                num_map[num_back].erase(find(num_map[num_back].begin(), num_map[num_back].end(), nums.size()-1));
                num_map[num_back].push_back(idx);
                swap(nums[idx], nums.back());
            }
            num_map[val].pop_back();
            nums.pop_back();
            return true;
        }
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int r = rand() % nums.size();
        return nums[r];
    }

private:
    unordered_map<int, vector<int>> num_map;
    vector<int> nums;
};

int main() {
//    clock_t start = clock();
    RandomizedCollection *obj = new RandomizedCollection();
    cout << obj->insert(0) << endl;
    cout << obj->insert(1) << endl;
    cout << obj->remove(0) << endl;
    cout << obj->insert(2) << endl;
    cout << obj->remove(1) << endl;
    cout << obj->getRandom() << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
