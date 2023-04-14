class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> subset;
        helper(candidates,target,0,subset,ans);
        return ans;
        
    }
    
    
    void helper(vector<int> &c, int target, int i, vector<int> &subset, vector<vector<int>> &ans){
                
        
        if(target==0){
            // if(find(ans.begin(),ans.end(), subset) != ans.end()){ return; }
            ans.push_back(subset); return;
        }
        
        if(target<0) return;
        
        if(i>=c.size()) return;
        
        
        
        subset.push_back(c[i]);       
        helper(c,target-c[i],i+1,subset,ans);
        subset.pop_back();
        
        while(i<c.size()-1 && c[i]==c[i+1]){ i++; }
        
        helper(c,target,i+1,subset,ans);
    }
};