class Solution {
    private:
    string lcs_tabulation(string s, string t, int l1, int l2, vector<vector<int>>&dp){
		

	// Base Case
	for(int i=0;i<=l2;i++) dp[0][i] = 0;
	for(int i=0;i<=l1;i++) dp[i][0] = 0;


	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){

			if(s[i-1]==t[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				int op1 = dp[i][j-1];
				int op2 = dp[i-1][j];
				dp[i][j] = max(op1, op2);
			}
		}
	}
        
        string ans = "";
        int i = l1;
        int j = l2;
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                ans += s[i-1];
                i--;j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans += s[i-1];
                i--;
            }
            else {
                ans+=t[j-1];
                j--;
            }
        }
        while(i>0) { ans += s[i-1]; i--; }
        while(j>0) { ans += t[j-1]; j--; }
    reverse(ans.begin(), ans.end());
	return ans;
}
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int l1 = str1.size();
        int l2 = str2.size();
        vector<vector<int>>dp(l1+1, vector<int>(l2+1, 0));
        return lcs_tabulation(str1, str2, l1, l2, dp);
    }
};