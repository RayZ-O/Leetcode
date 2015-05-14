// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate 
// the least recently used item before inserting a new item. 


class LRUCache{
private:
    unordered_map<int, pair<int, list<int>::iterator>> LRUDict;
    list<int> LRUList;
    int capacity;
    int size;
public:
    LRUCache(int capacity) {
        size = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(LRUDict.find(key) != LRUDict.end()) {
            auto &p = LRUDict.at(key);
            LRUList.erase(p.second);
            LRUList.push_back(key);
            p.second = --LRUList.end();
            return p.first;
        } else {
            return -1;
        }      
    }
    
    void set(int key, int value) {
       if(LRUDict.find(key) != LRUDict.end()) {
            auto &p = LRUDict.at(key);
            p.first = value;
            LRUList.erase(p.second);
            LRUList.push_back(key);
            p.second = --LRUList.end();   
       } else {
            if (size == capacity) {
                int lru = LRUList.front();
                LRUList.pop_front();
                LRUDict.erase(lru);
            } else {
                size++;
            }
            LRUList.push_back(key);
            LRUDict.emplace(key, make_pair(value, --LRUList.end()));
       }
    }
};