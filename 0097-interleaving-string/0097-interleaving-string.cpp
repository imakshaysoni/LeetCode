class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;

        int i = 0;
        int first = 0;
        int second = 0;
        vector<vector<vector<int>>> dp (s3.size()+1, vector<vector<int>> (s1.size()+1, vector<int> (s2.size()+1, -1)));
        return solve(s1,s2,s3,i, first, second, dp);

        // while(i<s3.size()){
        //     char ch = s3[i];
        //     if(ch == s1[first]) first++;
        //     else if(ch == s2[second]) second++;
        //     else return false;
        //     i++;
        // }

        // if(i==s3.size() and first==s1.size() and second==s2.size()) return true;
        // return false;

    }

    bool solve(string &s1, string &s2, string &s3, int i, int first,  int second, vector<vector<vector<int>>> &dp ){
        
        if(i==s3.size() and first==s1.size() and second==s2.size()) return true;
        
        if(i>=s3.size()) return false;
        
        if(i<s3.size() and first >= s1.size() and second>=s2.size()) return false;

        if(dp[i][first][second]!=-1) return dp[i][first][second];

        char ch = s3[i];
        if(first < s1.size() and second<s2.size() and ch!=s1[first] and ch!=s2[second]) return false;

        if(first < s1.size() and second<s2.size() and ch == s1[first] and ch == s2[second]){
            bool op1 = solve(s1,s2,s3,i+1, first+1, second, dp);
            bool op2 = solve(s1,s2,s3, i+1, first, second+1, dp);
            return dp[i][first][second] = op1 or op2;
        } 
        if(first<s1.size() and ch==s1[first]) return dp[i][first][second] = solve(s1,s2,s3, i+1, first+1, second, dp);
        if(second<s2.size() and ch==s2[second]) return dp[i][first][second]  = solve(s1,s2,s3, i+1, first, second+1, dp);
        cout<<i<<first<<second;
        return false;

    }
};