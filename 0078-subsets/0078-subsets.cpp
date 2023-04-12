class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       
        vector<vector<int>> ans;
        vector<int> subset;
        subarray(nums,0,subset,ans);
        return ans;
        
    }
    
   void subarray(vector<int> &v, int i, vector<int> &subset, vector<vector<int>> &ans){
        
        if(i==v.size()) {
            ans.push_back(subset);
            return;
        }
       
//         Include first Term
        subset.push_back(v[i]);
        subarray(v,i+1,subset,ans);
        
//         Ignore first term
        subset.pop_back();
        subarray(v,i+1,subset,ans);
       
       
        
        return;
        
        
    }
};