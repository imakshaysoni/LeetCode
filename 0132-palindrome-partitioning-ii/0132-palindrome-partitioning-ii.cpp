class Solution {
public:
    int minCut(string s) {
        vector<vector<int>> memo(s.size(), vector<int> (s.size(), -1));
        if (checkPalindrom(s, 0, s.size() - 1, memo))
            return 0;
        
        // vector<int> dp(s.size(), -1);
        // return solve(s, 0, dp) - 1;

        vector<int> dp(s.size()+1, 0);
        int n = s.size();
        for(int idx=n-1;idx>=0;idx--){
            string curr = "";
            int mini = INT_MAX;
            for (int index = idx; index < s.size(); index++) {
                curr += s[index];
                if (checkPalindrom(s, idx, index, memo))
                    mini = min(mini, 1 + dp[index+1]);
            }
            dp[idx] = mini;
        }
        return dp[0]-1;
        

    }
    bool checkPalindrom(string &s, int left, int right, vector<vector<int>> &memo) {
        int ldx =left;
        int rdx = right;
        if(memo[left][right]!=-1) return memo[ldx][rdx];
        while (left <= right) {
            if (s[left] != s[right]) {
                return memo[ldx][rdx] = false;
            }
            right--;
            left++;
        }
        return memo[ldx][rdx] = true;
    }
    // int solve(string &s, int idx, vector<int> &dp) {

    //     if (idx >= s.size())
    //         return 0;
    //     if(dp[idx]!=-1) return dp[idx];

    //     string curr = "";
    //     int mini = INT_MAX;
    //     for (int index = idx; index < s.size(); index++) {
    //         curr += s[index];
    //         if (checkPalindrom(s, idx, index))
    //             mini = min(mini, 1 + solve(s, index + 1, dp));
    //     }
    //     return dp[idx] = mini;
    // }
};