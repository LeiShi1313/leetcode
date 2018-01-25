#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Page {
public:
    int count;
    int key;
    int val;
    Page();
    Page(int k, int v): key(k), val(v), count(0) {}
};

class LRUCache {
public:
    LRUCache(int capacity): cap(capacity) {}

    int get(int key) {
        auto it = c_map.find(key);
        if (it != c_map.end()) {
            c_list.splice(c_list.begin(), c_list, c_map[key]);
            return c_map[key]->second;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        auto it = c_map.find(key);
        if (it != c_map.end()) {
            c_list.splice(c_list.begin(), c_list, it->second);
            it->second->second = value;
            return;
        }
        if (c_map.size() >= cap) {
            int key_to_remove = c_list.back().first;
            c_list.pop_back();
            c_map.erase(key_to_remove);
        }
        c_list.push_front(make_pair(key, value));
        c_map[key] = c_list.begin();
    }
private:
    int cap;
    unordered_map<int, list<pair<int, int> >::iterator> c_map;
    list<pair<int, int> > c_list;
};

int main() {

    LRUCache *obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout << obj->get(1) << endl;
    obj->put(3,3);
    cout << obj->get(2) << endl;
    obj->put(4,4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;

    obj = new LRUCache(1);
    obj->put(2,1);
    cout << obj->get(2) << endl;
    return 0;
}
