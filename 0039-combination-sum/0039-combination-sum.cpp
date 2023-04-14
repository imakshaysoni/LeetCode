class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> subSet;
        helper(candidates, target, ans, subSet, 0);
        return ans;
    }
    
    
    void helper(vector<int> &c, int target, vector<vector<int>> &ans, vector<int> &subSet, int i){
        
        
        if(target==0){
            ans.push_back(subSet); return;
        }
        
        
         if(target < 0)
            return;
        
         if(i >= c.size())
            return;         
        
//         Include First Term again & again
        subSet.push_back(c[i]);
        helper(c,target-c[i],ans,subSet, i);
            
        subSet.pop_back();
        helper(c, target, ans, subSet, i+1);
        
        
    }
};