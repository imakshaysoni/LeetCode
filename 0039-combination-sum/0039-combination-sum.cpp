class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        
        vector<vector<int>> v;
        vector<int> op;
        sort(c.begin(),c.end());
        solve(c,0,0,target,v, op);
        
        return v;
    }
    
    
    void solve(vector<int> &c, int i, int sum, int target, vector<vector<int>> &v, vector<int> op){
        
        if(i>=c.size()){ 
            return;
        }
        
        if(sum + c[i] == target){
            op.push_back(c[i]);
            v.push_back(op);
            return;
        }
            
        else if(sum+c[i] < target){
             vector<int> op1 = op;
            vector<int> op2 = op;
            
            op2.push_back(c[i]);
            solve(c,i,sum+c[i],target,v,op2);
            solve(c,i+1,sum,target,v,op1);
        }
        else{
            solve(c,i+1,sum+c[i],target,v,op);
        }
        
        
        
        
    }
};