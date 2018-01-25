#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class LFUCache {
public:
    LFUCache(int capacity): cap(capacity), curCap(0) {}

    int get(int key) {
        auto found = key_to_val_map.find(key);
        if (found == key_to_val_map.end()) {
            return -1;
        } else {
            count_to_list_map[found->second.second].erase(key_to_list_it_map[key]);
            found->second.second++;
            count_to_list_map[found->second.second].push_front(key);
            key_to_list_it_map[key] = count_to_list_map[found->second.second].begin();
            while (count_to_list_map[minFreq].empty()) minFreq++;
            return found->first;
        }
    }

    void put(int key, int value) {
        auto it = key_to_val_map.find(key);
        if (it != key_to_val_map.end()) {
            count_to_list_map[key_to_val_map[key].second].erase(key_to_list_it_map[key]);
        }
        if (curCap >= cap) {
            int key_to_remove = count_to_list_map[minFreq].back();
            key_to_list_it_map.erase(key_to_remove);
            key_to_val_map.erase(key_to_remove);
            count_to_list_map[minFreq].pop_back();
            curCap--;
        }
        key_to_val_map[key] = make_pair(value, 1);
        count_to_list_map[1].push_front(key);
        key_to_list_it_map[key] = count_to_list_map[1].begin();
        curCap++;
        minFreq = min(1, minFreq);
    }
private:
    int cap;
    int curCap;
    int minFreq;
    unordered_map<int, list<int>> count_to_list_map;
    unordered_map<int, pair<int, int>> key_to_val_map;
    unordered_map<int, list<int>::iterator> key_to_list_it_map;
};

int main() {

    LFUCache cache = *(new LFUCache(2));
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << ',';       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << ',';       // returns -1 (not found)
    cout << cache.get(3) << ',';       // returns 3.
    cache.put(4, 4);    // evicts key 1.
    cout << cache.get(1) << ',';       // returns -1 (not found)
    cout << cache.get(3) << ',';       // returns 3
    cout << cache.get(4) << endl;       // returns 4

    cache = *(new LFUCache(3));
    cache.put(2,2);
    cache.put(1,1);
    cout << cache.get(2) << ',';
    cout << cache.get(1) << ',';
    cout << cache.get(2) << ',';
    cache.put(3,3);
    cache.put(4,4);
    cout << cache.get(3) << ',';
    cout << cache.get(2) << ',';
    cout << cache.get(1) << ',';
    cout << cache.get(4) << endl;

    return 0;
}
