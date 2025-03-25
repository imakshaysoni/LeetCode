class Solution {
public:
    int jump(vector<int>& nums) {

        int maxR = -1;
        int lastIdx = 0;
        int step = 0;
        int n =nums.size();
        if(n==1) return 0;
        for(int i=0;i<n;i++){
            maxR = max(maxR, i+nums[i]);
            if(i==lastIdx){
                lastIdx = maxR;
                step++;
                if(maxR==n-1) return step;
            }
        }
        
    return step;
    }
};