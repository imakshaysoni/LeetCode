class LRUCache {
public:

    vector<int> vec;
    unordered_map<int,int> mapp;
    int cap=0;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mapp.find(key)==mapp.end()) return -1;
        // Move key to back (most recently used)
        vec.erase(remove(vec.begin(), vec.end(), key), vec.end());
        vec.push_back(key);
        return mapp[key];
        
    }
    
    void put(int key, int value) {
        if(mapp.find(key)!=mapp.end()){
            mapp[key]=value;
            vec.erase(remove(vec.begin(), vec.end(), key), vec.end());
        }
        else{
            if(mapp.size() >= cap){
                // delete least recently used;
                int lru_key = vec.front();
                vec.erase(vec.begin());
                mapp.erase(lru_key);
                mapp[key] = value;
            }
            else{
                mapp[key] = value;
            }
        }

        vec.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */