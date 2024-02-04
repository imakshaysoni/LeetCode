class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0;
        int ans=0;
        int n = nums.size();
        unordered_map<int,int> m;
        m[sum]=1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int find = sum-goal;
            if(m.find(find)!=m.end()){
                ans+=m[find];
            }
            m[sum]++;
        }
        
        return ans;
        
        
    }
};