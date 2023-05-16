class MinStack {
    vector<long long> st;
    long long mini = INT_MAX;
public:
    MinStack() {
    }
    
    void push(int val) {    
        if(st.empty()){
            st.push_back(val);
            mini = val;
        }
        else{
            if(val < mini){
                st.push_back(1LL*2*val - mini);
                mini = val;
            }
            else st.push_back(val);
        }
        
    }
    
    void pop() {
        if(st.empty()) return;
        long t = st.back();
        st.pop_back();
        if(t<mini){
            mini = 2*mini*1LL - t;
        }
    }
    
    int top() {
        long t1 = st.back();
        if(t1 < mini) return mini;
        return t1;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


// TC : O(1), SC : O(2N) Used vector of pair

// class MinStack {
// private:
//     vector<pair<int,int>> st;
// public:
//     MinStack() {
//     }
    
//     void push(int val) {
//         if(st.empty()) st.push_back({val,val});
//         else st.push_back({val,min(val, st.back().second)});
//     }
    
//     void pop() {
//         st.pop_back();
//     }
    
//     int top() {
//         return st.back().first;
//     }
    
//     int getMin() {
//         return st.back().second;
//     }
// };