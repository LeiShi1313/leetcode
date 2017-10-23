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

class RangeModule {
public:
    set<pair<int, int>> ranges;
    RangeModule() {

    }

    void addRange(int left, int right) {
        for (auto it = ranges.begin(); it != ranges.end(); ) {
            int x = it->first, y = it->second;
            if (! (right < x || left > y)) {
                left = min(left, x);
                right = max(right, y);
                it = ranges.erase(it);
            } else it++;
        }
        ranges.insert(make_pair(left, right));
        for (auto it=ranges.begin(); it!= ranges.end();it++) {
            cout << it->first << "->" << it->second << ',';
        }
        cout << endl;
    }

    bool queryRange(int left, int right) {
        for (auto it: ranges) {
            int x = it.first, y = it.second;
            if (x <= left && y >= right) {
                return true;
            }
        }
        return false;
    }

    void removeRange(int left, int right) {
        for (auto it = ranges.begin(); it != ranges.end(); ) {
            int x = it->first, y = it->second;
            if (! (right <= x || left >= y)) {
                it = ranges.erase(it);

                // l x y r
                if (left <= x && y <= right) continue;

                // l x r y
                if (left <= x && right > x && right <= y) {
                    ranges.insert(make_pair(right, y));
                    continue;
                }

                // x l y r
                if (x <= left && left < y && right >= y) {
                    ranges.insert(make_pair(x, left));
                    continue;
                }

                // x l r y
                if (x <= left && right <= y) {
                    ranges.insert(make_pair(x, left));
                    ranges.insert(make_pair(right, y));
                    continue;
                }
                throw;
            } else ++it;
        }
    }
};

int main() {

    RangeModule *obj = new RangeModule();
    obj->addRange(10, 20);
    obj->addRange(14, 35);

    return 0;
}
