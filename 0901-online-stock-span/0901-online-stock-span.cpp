class StockSpanner {
    
        vector<int> arr;
public:
    StockSpanner() {
        stack<int> s;
    }
    
    int next(int price) {
        arr.push_back(price);
        int count=0;
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i] <= arr[arr.size()-1]) count++;
            else break;
        }
        return count;
        
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */