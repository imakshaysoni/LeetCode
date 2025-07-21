class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {


        // Optimal
        int posIdx = 0;
        int negIdx=1;

        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i=0;i<n;i++){
            if(nums[i]>=0) {
                ans[posIdx] = nums[i];
                posIdx+=2;
            }
            else{
                ans[negIdx] = nums[i];
                negIdx +=2;
            }
        }
        return ans;

        
        // int n = nums.size();
        // vector<int> pos;
        // vector<int> neg;

        // for(int i=0;i<n;i++){
        //     if(nums[i]>=0) pos.push_back(nums[i]);
        //     else neg.push_back(nums[i]);
        // }

        // vector<int> ans(n, 0);
        // int idx = 0;
        // int posIdx = 0;
        // int negIdx = 0;
        // while(idx<n-1){
        //     ans[idx] = pos[posIdx];
        //     posIdx++;
        //     ans[idx+1] = neg[negIdx];
        //     negIdx++;

        //     idx += 2;
        // }

        // return ans;
        // TC: O(N) + o(N)
        // SC: O(N/2) + O(N/2)
    }
};