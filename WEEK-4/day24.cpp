/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?
*/

class LRUCache {
public:
      int cap;
    list<int>key_list;
    unordered_map<int,int>mp;
    
    LRUCache(int capacity) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cap = capacity;
    }
    
    int get(int key) {
       if(mp.find(key) == mp.end() ) return -1;
          else{
            key_list.remove(key);
            key_list.push_back(key);
            return mp[key];
        }
    }
    
   void put(int key, int value) {
        if(mp.find(key) != mp.end() ){
            mp.erase(key);
            key_list.remove(key);
        }
        if(key_list.size() == cap){
           int temp = key_list.front();
            key_list.pop_front();
            mp.erase(temp);
        }
        mp[key] = value;
        key_list.push_back(key);
    }

};