class LRUCache {
public:
    list<int> l;
    unordered_map<int,list<int>::iterator> address;
    unordered_map<int,int> m;
    int cap,siz;
    LRUCache(int capacity) {
        
        cap=capacity;
        siz=0;
        
    }
    
    int get(int key) {
//         if Key is present in cache
        if(m.find(key)==m.end()) return -1;
//         Erase first
        l.erase(address[key]);
        address.erase(key);
//         Now Inserting at front
        l.push_front(key);
        address[key] = l.begin();
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            m[key]=value;
//         Erase first
            l.erase(address[key]);
            address.erase(key);
//         Now Inserting at front
            l.push_front(key);
            
            address[key]=l.begin();
        }
        else{
            
            if(cap==siz){
                int k = l.back();
                address.erase(k);
                l.pop_back();
                m.erase(k);
                siz--;
            }
            l.push_front(key);            
            address[key] = l.begin();
            m[key]=value;         
            siz++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */