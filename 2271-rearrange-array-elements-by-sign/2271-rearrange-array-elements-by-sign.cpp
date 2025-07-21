class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;

        for(int i=0;i<n;i++){
            if(nums[i]>=0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }

        vector<int> ans(n, 0);
        int idx = 0;
        int posIdx = 0;
        int negIdx = 0;
        while(idx<n-1){
            ans[idx] = pos[posIdx];
            posIdx++;
            ans[idx+1] = neg[negIdx];
            negIdx++;

            idx += 2;
        }

        return ans;
    }
};