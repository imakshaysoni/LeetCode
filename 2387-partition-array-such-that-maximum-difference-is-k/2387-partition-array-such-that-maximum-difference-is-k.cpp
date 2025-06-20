class Solution {
public:
    int ans = INT_MAX;
    int partitionArray(vector<int>& nums, int k) {

        // int res =  solve(nums, k, 0);
        sort(nums.begin(), nums.end());
        int left= 0;
        int right = 0;
        int part = 0;
        
         while(right<nums.size()){

            if(nums[right] - nums[left] > k){
                part++;
                left = right;
            }
            right++;

        }
        return part+1;
        
    }
    int solve(vector<int> &nums, int k, int idx){

        if(idx >= nums.size()) {
            return 0;
        }


        int mini = INT_MAX;
        int minn = INT_MAX;
        int maxi = INT_MIN;
        for(int i=idx;i<nums.size();i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
            int op1 = INT_MAX, op2=INT_MAX;
            if(maxi - mini <= k){
                op1 =  1 + solve(nums, k, i+1);
            }
            else{
                
                op2 = solve(nums, k , i+1);
            }

            minn =  min(op1, op2);
        }
        return minn;

    }
};