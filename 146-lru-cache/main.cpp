#include <iostream>

#include <list>
#include <utility>
#include <unordered_map>


using std::list;
using std::pair;
using std::unordered_map;


class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        auto find = keys.find(key);
        if (find != keys.end()) {
            auto iter = find->second;
            int result = iter->first;
            values.push_front(*iter);
            values.erase(iter);
            keys[key] = values.begin();
            return result;
        } else {
            return -1;
        }
    }

    void set(int key, int value) {
        auto find = keys.find(key);
        if (find == keys.end()) {
            if (keys.size() >= m_capacity) {
                keys.erase(values.back().second);
                values.pop_back();
            }
        } else {
            auto iter = find->second;
            values.erase(iter);
        }
        values.push_front(std::make_pair(value, key));
        keys[key] = values.begin();
    }
private:
    int m_capacity;
    typedef list<std::pair<int, int>> list_type;
    unordered_map<int, list_type::iterator> keys;
    list_type values;
};


int main() {
    LRUCache lru(2);
    lru.set(2, 1);
    lru.set(1, 1);
    std::cout << lru.get(2) << std::endl;
    lru.set(4, 1);
    std::cout << lru.get(1) << std::endl;
    std::cout << lru.get(2) << std::endl;
    return 0;
}
