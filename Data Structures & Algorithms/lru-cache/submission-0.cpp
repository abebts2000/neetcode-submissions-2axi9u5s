class LRUCache {
    unordered_map<int, pair<int,list<int>::iterator>>mp;
    list<int>order;
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
         return -1;
        order.erase(mp[key].second);
        order.push_back(key);
        mp[key].second = prev(order.end());
        return mp[key].first;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {    
            order.erase(mp[key].second);
            order.push_back(key);
            mp[key] = {value, prev(order.end())};
        }
        else
        {
            if(mp.size() == size)
            {
                int front = order.front();
                order.pop_front();
                mp.erase(front);
            }
            order.push_back(key);
            mp[key] = {value, prev(order.end())};
        }
    }
};
