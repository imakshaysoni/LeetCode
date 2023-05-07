class Solution {
public:
    bool canCross(vector<int>& stones) {
    
        
        
        vector<vector<int>> dp(stones.size()+1, vector<int> (2001,-1));
        return solve(stones, 0, 1, dp);
    }
    
    
    bool solve(vector<int> &s, int index, int jumps, vector<vector<int>> &dp){
        
        if(index==s.size()-1) return true;
        
        if(index<0 || index > s.size()) return false;
        
        if(jumps <= 0) return false;
        
        if(dp[index][jumps]!=-1) return dp[index][jumps];
        
        int idx = getIdx(s, s[index]+jumps, index);
        if(idx==-1) return dp[index][jumps] = false;
        index = idx;
        
        
        bool op1 = solve(s, index, jumps, dp);
        bool op2 = solve(s, index, jumps-1, dp);
        bool op3 = solve(s, index, jumps+1, dp);
        
        return dp[index][jumps] = op1 || op2 || op3;
        
        
    }
    
    int getIdx(vector<int> &s, int val, int index){
        
        for(int i=index;i<s.size();i++){
            if(s[i]==val) return i;
        }
        
        return -1;
    }
};