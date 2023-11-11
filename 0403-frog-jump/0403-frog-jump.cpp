class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,int>m;
        for(int i=0;i<stones.size();i++){
            m[stones[i]] = i;
        }
        
        vector<vector<int>> dp(stones.size()+1, vector<int>(2001,-1));
        return frog(stones, 0, 1, dp, m);
    }
    
    bool frog(vector<int>&stones, int index, int jump, vector<vector<int>> &dp, unordered_map<int,int> &mapper){
        if(index==stones.size()-1) return true;
        if(index>=stones.size()) return false;     
        if(jump<=0) return false;
        
        if(dp[index][jump]!=-1) return dp[index][jump];
        
        // int new_index = getIdx(stones, index, stones[index]+jump); //O(N)
        int new_index = getIdxMap(mapper, stones[index]+jump); //O(1)
        if(new_index==-1) return false;
        index=new_index;    
        
        int op1 = frog(stones, index, jump, dp, mapper);
        if(op1) return dp[index][jump] = true;
        int op2 = frog(stones, index, jump + 1, dp, mapper );
        if(op2) return dp[index][jump] = true;
        int op3 = frog(stones, index, jump - 1, dp, mapper);
        dp[index][jump] = op1 || op2 ||op3;
        return dp[index][jump];
    }
    
    int getIdx(vector<int> &stones, int index, int val){
        for(int i=index;i<stones.size();i++){
            if(stones[i]==val) return i;
        }
        return -1;
    }
    
    int getIdxMap(unordered_map<int,int>&m, int val){
        if(m.find(val)!=m.end()) return m[val];
        return -1;
    }
};