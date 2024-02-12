class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return 0;
        
        int lastIdx = 0;
        int jumps=0;
        int cover = 0;
        for(int i=0;i<n;i++){
            
            cover = max(cover, i + nums[i]);
            
            if(i==lastIdx){
                jumps++;
                lastIdx = cover;
                if(cover>=n-1) return jumps;
            }
            
            
        }
        return jumps;
    }
};