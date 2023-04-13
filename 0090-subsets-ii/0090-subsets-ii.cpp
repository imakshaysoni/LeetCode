class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        uniqueSubSets(nums,subset,0, ans);
        return ans;    
        
    }
    
    void uniqueSubSets(vector<int> &v, vector<int> subset, int i, vector<vector<int>> &ans){
        
        if(i>=v.size()){
            ans.push_back(subset);
            return;
        }
        
        
        // Take First Term
        subset.push_back(v[i]);
        uniqueSubSets(v,subset,i+1,ans);
        
        
        subset.pop_back();
        
        while(i<v.size()-1 && v[i]==v[i+1])i++;
//         Ignore the first term
        uniqueSubSets(v,subset,i+1,ans);
    }
    
};