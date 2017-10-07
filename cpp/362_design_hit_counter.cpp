//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        // consider remove item here too for performance
        hits.push(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!hits.empty() && hits.front()+299 < timestamp) {
            hits.pop();
        }
        return hits.size();
    }

private:
    queue<int> hits;
};

int main() {

    int timestamp;
    HitCounter *obj = new HitCounter();
    obj->hit(1);
    obj->hit(2);
    obj->hit(3);
    cout << obj->getHits(4) << endl;
    obj->hit(300);
    cout << obj->getHits(300) << endl;
    cout << obj->getHits(301) << endl;

    return 0;
}
