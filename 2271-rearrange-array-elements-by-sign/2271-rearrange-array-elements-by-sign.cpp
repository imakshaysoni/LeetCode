class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIdx = 0;
        int negIdx = 1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) {
                ans[posIdx] = nums[i];
                posIdx+=2;
            }
            else {
                ans[negIdx] = nums[i];
                negIdx+=2;
            }
        
        }
        return ans;
        
        // vector<int> pos;
        // vector<int> neg;
        
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i] >= 0) pos.push_back(nums[i]);
        //     else neg.push_back(nums[i]);
        // }

        // int n = nums.size();
        // int posIdx=0;
        // int negIdx=0;
        // int idx=0;
        // while(idx<n-1 and posIdx < pos.size() and negIdx < neg.size()){
        //     nums[idx] = pos[posIdx];
        //     nums[idx+1] = neg[negIdx];
        //     idx+=2;
        //     posIdx++;
        //     negIdx++;
        // }
        // while(posIdx<pos.size()){
        //     nums[idx] = pos[posIdx];
        // }

        // while(negIdx<neg.size()){
        //     nums[idx] = pos[negIdx];
        // }
        // return nums;

    }
};