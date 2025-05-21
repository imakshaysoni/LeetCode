class Solution {
public:
    bool check_all_zeros(vector<int> &nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) return false;
        }
        return true;
    }
    bool checkNow(vector<int> &nums, vector<vector<int>> &queries, int idx){
        int n = nums.size();
        vector<int> diff(n, 0);
        
        for(int k=0;k<=idx;k++){
            int left = queries[k][0];
            int right = queries[k][1];
            int val = queries[k][2];

            diff[left] += val;
            if(right+1<n) diff[right+1] += -val;
        }
        
        vector<int> res;
        int cSum = 0;
        for(int i=0;i<n;i++){
            cSum += diff[i];
            res.push_back(cSum);
            if(nums[i] > res[i]) return false;
        }
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i] > res[i]) return false;
        // }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int qn = queries.size();
        if(check_all_zeros(nums)) return 0;
        
        // bs
        int left = 0;
        int right = qn-1;
        int ans = -1;
        while (left<=right){
            int mid = (left + (right-left)/2);
            if(checkNow(nums, queries, mid)){
                ans = mid+1;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
        // linear search here
        // for(int k=0;k<qn;k++){
        //     int left = queries[k][0];
        //     int right = queries[k][1];
        //     int val = queries[k][2];

        //     diff[left] += val;
        //     if(right+1<n) diff[right+1] += -val;
        //     if(checkNow(diff, nums)) return k+1;
        // }
        // return -1;
    }
};