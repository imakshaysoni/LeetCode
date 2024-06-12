class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
        
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size()==0){
          maxHeap.push(num);
            return;  
        } 
        int top = maxHeap.top();
        if(num < top){
            if(maxHeap.size()==minHeap.size()){
                maxHeap.push(num);
            }
            else if (maxHeap.size() > minHeap.size() ){
                minHeap.push(top);
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
        else{
            if(maxHeap.size()==minHeap.size()){
                minHeap.push(num);
                int top_ele = minHeap.top(); minHeap.pop();
                maxHeap.push(top_ele);
            }
            else{
                minHeap.push(num);
            }
        }
        
        
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            return double((maxHeap.top() + minHeap.top()) / 2.0);
        }
        return double(maxHeap.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */