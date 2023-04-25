class Solution {
public:
    int numDecodings(string s) {
        
        
        int ans;
        vector<int> dp(s.size()+1, 0);
        ans = helper(s, 0, dp);
        return ans;
        
    }
    
    
    int helper(string &s, int i, vector<int> &dp){        
        if(i==s.size()) return 1;
        if(i>s.size()) return 0;
        int ans =0;
        int op1 = s[i]-'0';
        int op2;
        if(dp[i]!=0) return dp[i];
        if(op1 > 0) ans+=helper(s,i+1,dp);
        if(i < s.size()-1){
            op2 = op1*10 + s[i+1]-'0';
        }
        if(op1>0 && op2>0 && op2 <=26) ans+=helper(s,i+2,dp);
        
        return dp[i]=ans;       
        
    }
    
    // int helper(string &s, int i, vector<int> &dp){
//         if(i==s.size()) return 1;
//         if(i>s.size()) return 0;
//         int ans=0;
        
//         if(dp[i]!=0) return dp[i];
//         if(s[i]!='0') dp[i] += helper(s,i+1, dp);
        
//         if(i+1 < s.size() && s[i] == '1' || s[i] == '2' && s[i+1] <= '6' ){
//             dp[i]+= helper(s,i+2, dp);
//         }
        
//         return dp[i];
        
//     }
};