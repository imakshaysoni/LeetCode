class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> subset;
        vector<vector<int>> ans;
        // vector<int> subset;
        helper(1,n,k,ans, subset);
        
        return ans;
    }
    
    
    void helper(int i, int n, int k, vector<vector<int>> &ans, vector<int> &subSets){
        
        
        if(k==0){
            ans.push_back(subSets);
            return;
        }
        if(i>n) return;
                
//         Taking the first term
        subSets.push_back(i);
        helper(i+1,n,k-1,ans,subSets);
        
        
//         Ignorering the value
        subSets.pop_back();
        helper(i+1,n,k,ans,subSets);
        
        
    }
    
     
};


//  Mehtod whihc i figure out on my own, 80% correct
// void helper(int i ,int n, int k, vector<vector<int>> &ans, vector<int> &subset){
        
        
//         if(subset.size()==k){ ans.push_back(subset); return;}
        
//         for(int j=i;j<n+1;j++){
//             subset.push_back(j);
//             helper(j+1,n,k,ans,subset);
//             subset.pop_back();
//         }
//     }