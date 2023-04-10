class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        
        int n = nums.size();
        if(n<2) return true;
        int reach = 0;
        for(int i=0;i<n-1 && i <= reach;i++){
            int currReach = i+nums[i];
            reach = max(currReach, reach);
        }
        
        return reach>=n-1;
        
    }
};