// class Solution {
// public:
//     int t[301][11];
//     int solve(vector<int>& mat, int n, int idx, int d) {
//         if(d == 1)
//             return *max_element(begin(mat)+idx, end(mat));
        
//         if(t[idx][d] != -1)
//             return t[idx][d];
    
        
//         int Max = INT_MIN;
//         int result = INT_MAX;
        
//         for(int i = idx; i<=n-d; i++) {
//             Max = max(Max, mat[i]);
//             result = min(result, Max + solve(mat, n, i+1, d-1));
//         }
//         return t[idx][d] = result;
//     }
    
//     int minDifficulty(vector<int>& jobDifficulty, int d) {
//         int n = jobDifficulty.size();
//         if(n < d)
//             return -1;
//         memset(t, -1, sizeof(t));
//         return solve(jobDifficulty, n, 0, d);
//     }
// };

class Solution {
public:
    // int result=INT_MAX;
    int minDifficulty(vector<int>& jd, int d) {
        
        int n = jd.size();
        if(d>n) return -1; 
        
        vector<vector<int>> dp(n+1, vector<int> (d+1, -1));
        
        int x = solve(jd, d, 0, dp);
        // cout<<result<<" "<<x;
        return x;
        
    }
    
    int solve(vector<int> &j, int d, int index, vector<vector<int>> &dp){
        
        
        if(index>=j.size()) return INT_MAX;
        
        if(d==1){
            int temp = getMax(j, index);
            return temp;
        }
        
        if(dp[index][d]!=-1) return dp[index][d];
        
        // vector<int> s;
        int Max = INT_MIN;
        int temp_ans=0;
        int result = INT_MAX;
        for(int i=index;i<j.size();i++){
            // s.push_back(j[i]);
            Max = max(Max, j[i]);
            // int Max = getMax(s,0);
            temp_ans = solve(j, d-1, i+1, dp);
            if(temp_ans!=INT_MAX)
           result = min(result, temp_ans + Max);                           
        }        
        
        return dp[index][d]=result;        
    }
    
    int getMax(vector<int> &s, int index){
        int maxx=-1;
        for(int i=index;i<s.size();i++){
            maxx = max(maxx, s[i]);
        }
        
        return maxx;
    }
    
    
};