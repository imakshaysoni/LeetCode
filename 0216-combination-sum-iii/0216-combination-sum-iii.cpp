class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        vector<int> subset;
        helper(k, n, 1, subset, ans);
        
        return ans;
        
    }
    
    
    void helper(int k, int n, int i, vector<int> &subset, vector<vector<int>> &ans){
        
        
        if(k==subset.size()){
            if(n==0){ ans.push_back(subset); return; }
            return;
        }
        
        if(i>9) return;
        
        
//         Take the ith element
        subset.push_back(i);
        helper(k,n-i,i+1,subset,ans);
        subset.pop_back();
        
        
        helper(k,n,i+1,subset,ans);
        
        
        
    }
};