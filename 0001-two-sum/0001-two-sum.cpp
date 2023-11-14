class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> st;        
        for(int i=0;i<n;i++){
            int required_sum = target - nums[i];
            if(st.find(required_sum)!=st.end()){
                return {i, st[required_sum]};
            }
            else{
                st[nums[i]]=i;
            }
        }
        
        // O(N2)
        return {-1,-1};        
        
    }
};