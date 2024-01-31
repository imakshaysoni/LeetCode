class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            int target = -nums[i];
            int left = i+1;
            int right = n-1;
            
            while(left<right){
                if(nums[left]+nums[right]==target){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while(left<right and nums[left]==nums[left+1]) left++;
                    while(right>left and nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if (nums[left]+nums[right]<target){
                    left++;
                }
                else{
                    right--;
                }
            }
            while(i<n-1 && nums[i]==nums[i+1]) i++;
            
            
        }
        
        return ans;
            
    }
};