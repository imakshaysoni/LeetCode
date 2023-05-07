// class Solution {
// public:
//     bool canCross(vector<int>& stones) {
    
        
        
//         vector<vector<int>> dp(stones.size()+1, vector<int> (2001,-1));
//         return solve(stones, 0, 1, dp);
//     }
    
    
//     bool solve(vector<int> &s, int index, int jumps, vector<vector<int>> &dp){
        
//         if(index==s.size()-1) return true;
        
//         if(index<0 || index > s.size()) return false;
        
//         if(jumps <= 0) return false;
        
//         if(dp[index][jumps]!=-1) return dp[index][jumps];
        
//         int idx = getIdx(s, s[index]+jumps, index);
//         if(idx==-1) return dp[index][jumps] = false;
//         index = idx;
        
        
//         bool op1 = solve(s, index, jumps, dp);
//         bool op2 = solve(s, index, jumps-1, dp);
//         bool op3 = solve(s, index, jumps+1, dp);
        
//         return dp[index][jumps] = op1 || op2 || op3;
        
        
//     }
    
//     int getIdx(vector<int> &s, int val, int index){
        
//         for(int i=index;i<s.size();i++){
//             if(s[i]==val) return i;
//         }
        
//         return -1;
//     }
// };

class Solution {
public:
    unordered_map<int,bool> mp;
    bool recursion(int pos, int prevStep, vector<int>& arr, int n, map<pair<int,int>,bool>& memo){

        if(mp[pos]== false || pos > arr[n-1]) return false;
        if(pos == arr[n-1]) return true;  
        if(memo.find({pos,prevStep}) != memo.end()) return memo[{pos,prevStep}];

        bool isPossible;

        if(pos==0){
            isPossible = recursion(pos+1,1,arr,n,memo);
        }
        else{
            if(prevStep-1>0) 
                isPossible = recursion(pos+(prevStep-1),prevStep-1,arr,n,memo);
            if(isPossible) return true;
            isPossible = recursion(pos+prevStep,prevStep,arr,n,memo);
            if(isPossible) return true;
            isPossible = recursion(pos+(prevStep+1),prevStep+1,arr,n,memo);
            if(isPossible) return true;
        }
        
        memo[{pos,prevStep}] = isPossible;
        return isPossible;

    }

    bool canCross(vector<int>& stones) {
        
        for(auto itr : stones){ 
            mp[itr] = true;
           
        }
        map<pair<int,int>,bool> memo;
        int n = stones.size();
        return recursion(0,1,stones,n,memo);
    }
};