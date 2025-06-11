class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;

        int first = 0;
        int second = 0;
        vector<vector<int>> dp (s1.size()+1, vector<int> (s2.size()+1, -1));
        return solve(s1,s2,s3,first, second, dp);

    }

    bool solve(string &s1, string &s2, string &s3, int first,  int second, vector<vector<int>> &dp ){
        
        if(first==s1.size() and second==s2.size()) return true;
        
        if(first+second >=s3.size()) return false;
        
        if(first + second <s3.size() and first >= s1.size() and second>=s2.size()) return false;

        if(dp[first][second]!=-1) return dp[first][second];

        char ch = s3[first+second];
        if(first < s1.size() and second<s2.size() and ch!=s1[first] and ch!=s2[second]) return false;

        if(first < s1.size() and second<s2.size() and ch == s1[first] and ch == s2[second]){
            bool op1 = solve(s1,s2,s3, first+1, second, dp);
            bool op2 = solve(s1,s2,s3, first, second+1, dp);
            return dp[first][second] = op1 or op2;
        } 
        if(first<s1.size() and ch==s1[first]) return dp[first][second] = solve(s1,s2,s3, first+1, second, dp);
        if(second<s2.size() and ch==s2[second]) return dp[first][second]  = solve(s1,s2,s3, first, second+1, dp);
        // cout<<i<<first<<second;
        return false;

    }
};