class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        uniqueSubSets(nums,0, ans, subset);
        return ans;    
        
    }
    
    
    void uniqueSubSets(vector<int> &v, int i, vector<vector<int>> &ans, vector<int> &subset){
        
        
        // if(i>=v.size()){
        //     ans.push_back(subset);
        //     return;
        // }
        
        ans.push_back(subset);
        
        for(int k=i;k<v.size();k++){
            if(i == k || v[k]!=v[k-1])
            {subset.push_back(v[k]);
            uniqueSubSets(v,k+1,ans,subset);
            subset.pop_back();}
        }
        
        
    }
        
    
};