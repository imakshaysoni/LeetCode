class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        uniqueSubSets(nums,subset,0, ans, false);
        return ans;    
        
    }
    
    void uniqueSubSets(vector<int> &v, vector<int> subset, int i, vector<vector<int>> &ans, bool prev){
        
        if(i>=v.size()){
            ans.push_back(subset);
            return;
        }
        
        
        uniqueSubSets(v,subset,i+1,ans,false);
        //Method 1:  while(i<v.size()-1 && v[i]==v[i+1])i++;
        
        //**********************************//
//         Prev used value Logic
        
        if(i>0 && v[i]==v[i-1] && !prev){
            return;
        }
        
            
        // Take First Term
        subset.push_back(v[i]);
        uniqueSubSets(v,subset,i+1,ans, true);             
        subset.pop_back();
        
        
        
        
        
        
        
        
        //**********************************//
//         Ignore the first term
        
    }
    
};