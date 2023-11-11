class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        vector<vector<int>> dp(stones.size()+1, vector<int>(2001,-1));
        return frog(stones, 0, 1, dp);
    }
    
    bool frog(vector<int>&stones, int index, int jump, vector<vector<int>> &dp){
        if(index==stones.size()-1) return true;
        if(index>=stones.size()) return false;     
        if(jump<=0) return false;
        
        if(dp[index][jump]!=-1) return dp[index][jump];
        
        int new_index = getIdx(stones, index, stones[index]+jump);
        if(new_index==-1) return false;
        index=new_index;    
        
        int op1 = frog(stones, index, jump, dp);
        int op2 = frog(stones, index, jump + 1, dp );
        int op3 = frog(stones, index, jump - 1, dp);
        dp[index][jump] = op1 || op2 ||op3;
        return dp[index][jump];
    }
    
    int getIdx(vector<int> &stones, int index, int val){
        for(int i=index;i<stones.size();i++){
            if(stones[i]==val) return i;
        }
        return -1;
    }
};