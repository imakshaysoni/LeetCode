class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
     
        vector<vector<int>> ans;
        vector<int> permuations;
        solve(nums, 0, permuations, ans);
        return ans;
    }
    
    
    void solve(vector<int> nums, int index, vector<int> &p, vector<vector<int>> &ans){
        
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            swap(nums[index], nums[i]);
            solve(nums, index+1, p, ans);
            swap(nums[index], nums[i]);
        }    
        
        
        
        
    }
};