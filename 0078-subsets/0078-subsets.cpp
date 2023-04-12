class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       
        vector<vector<int>> ans;
        vector<int> subset;
        // subarray(nums,0,subset,ans);
        // return ans;
        return SubSets(nums,0);
        
    }
    
    
    
    vector<vector<int>> SubSets(vector<int> &v, int i){
        
        if(i==v.size()) return {{}};
        
        vector<vector<int>> partialAns = SubSets(v,i+1);
        vector<vector<int> > ans;
        for(auto x: partialAns){
            ans.push_back(x);
        }
        
        for(auto x: partialAns){
            x.push_back(v[i]);
            ans.push_back(x);
        }
        
        return ans;
    }
    
//    void subarray(vector<int> &v, int i, vector<int> &subset, vector<vector<int>> &ans){
        
//         if(i==v.size()) {
//             ans.push_back(subset);
//             return;
//         }
       
// //         Include first Term
//         subset.push_back(v[i]);
//         subarray(v,i+1,subset,ans);
        
// //         Ignore first term
//         subset.pop_back();
//         subarray(v,i+1,subset,ans);
       
       
        
//         return;
        
        
//     }
};