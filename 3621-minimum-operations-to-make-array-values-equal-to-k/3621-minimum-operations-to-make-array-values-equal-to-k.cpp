class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st;
        int disCount = 0;
        for(auto it: nums){
            if(it > k and st.find(it)==st.end()){
                disCount++;
                st.insert(it);
            }
            if(it < k) return -1;
        }
        return disCount;
        
    }
};