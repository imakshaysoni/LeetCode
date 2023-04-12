class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        permutation(nums,0,ans);
        return ans;
        
        
    }
    
    void permutation(vector<int> &v, int pos, vector<vector<int>> &ans){
        
        if(pos>=v.size()){
            ans.push_back(v);
            return;
        }
        
        for(int i=pos;i<v.size();i++){
            
            swap(v[pos],v[i]);
            permutation(v,pos+1,ans);
            swap(v[pos],v[i]);
        }     
        
        
        
        
        return;
        
        
    }
    
};