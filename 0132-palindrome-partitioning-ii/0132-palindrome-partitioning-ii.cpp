class Solution {
public:
    int minCut(string s) {
        
        if (checkPalindrom(s, 0, s.size() - 1))
            return 0;
        
        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp) - 1;
    }
    bool checkPalindrom(string &s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            right--;
            left++;
        }
        return true;
    }
    int solve(string &s, int idx, vector<int> &dp) {

        if (idx >= s.size())
            return 0;
        if(dp[idx]!=-1) return dp[idx];

        string curr = "";
        int mini = INT_MAX;
        for (int index = idx; index < s.size(); index++) {
            curr += s[index];
            if (checkPalindrom(s, idx, index))
                mini = min(mini, 1 + solve(s, index + 1, dp));
        }
        return dp[idx] = mini;
    }
};