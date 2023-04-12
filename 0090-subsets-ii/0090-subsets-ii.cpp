class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> subset;
        subSets(nums,0,ans, subset);
        return ans;
        
    }
    
    void subSets(vector<int> &v, int i, vector<vector<int>> &ans, vector<int> &subset){
        
        
       if(i>=v.size()){
           ans.push_back(subset);
           return;
       } 
        
//         unordered_set<int> s;
        
// //         Take the first term
//         while(s.find(v[i])!=s.end()){
//             i++;
//         }
//         s.insert(v[i]);
        
        subset.push_back(v[i]);
        subSets(v,i+1,ans,subset);
        
//         Not taking first value
        subset.pop_back();
        
        while(i+1<v.size() && v[i]==v[i+1]) i++;
        subSets(v,i+1,ans,subset);
        
    }
};