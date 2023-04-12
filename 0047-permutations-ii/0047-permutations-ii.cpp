class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if(nums.size()<2) return {nums};
        helper(nums,0,ans);
        return ans;
        
    }
    
    void helper(vector<int> &v, int pos, vector<vector<int>> &ans){
        
        if(pos>=v.size()){
            ans.push_back(v);
            return;
        }
        unordered_set<int> s;
        for(int i=pos;i<v.size();i++){       
            if(s.find(v[i])!=s.end()) continue;
            s.insert(v[i]);
            swap(v[pos],v[i]);
            helper(v,pos+1,ans);
            swap(v[pos],v[i]);
        }
        return;        
        
    }
};