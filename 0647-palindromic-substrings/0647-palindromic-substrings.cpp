class Solution {
public:
    int countSubstrings(string s) {       
        
         int n = s.size();
        if(n==0 || n==1){
            return n;
        }
        int cnt = 0;
        for(int i=0;i<n; i++){
            int j = i;
            int k = i;
            //odd
            while(j>=0 && k<n && s[j]== s[k]){
                j--;
                k++;
                cnt++;
            }
            //evenn 
            j = i;
            k = i+1;
            while(j>=0 && k<n && s[j]==s[k]){
                j--;
                k++;
                cnt++;
            }
        }
        return cnt;
    }
        
//         vector<vector<int>> dp(s.size()+1,vector<int> (s.size()+1,-1));
//         int count=0;
//         for(int i=0;i<s.size();i++){
//             for(int j=i;j<s.size();j++){
//                 if(dp[i][j]!=-1) {
//                     count += dp[i][j];
//                     continue;
//                 }
//                 count += helper(s,i,j, dp);
//             }
//         }
//         return count;
//     }
    
//     int helper(string &s, int i, int j, vector<vector<int>> &dp){
//         if(i>=j) return dp[i][j]=1;
//         return dp[i][j] = s[i] == s[j] ? helper(s,i+1,j-1, dp) : 0;
//     }
        
        
        
// //         TLE
// //         vector<string> strSubset;
// //         for(int i=0;i<s.size();i++){
// //             string temp;
// //             for(int j=i;j<s.size();j++){
// //                 temp+=s[j];
// //                 strSubset.push_back(temp);
// //             }
// //         }
        
// //         int count=0;
// //         for(auto str: strSubset){
// //             if(isPalindrome(str)) count++;
// //         }
// //         // for(auto x: strSubset) cout<<x<<endl;
// //         return count;
        
// //     }
    
// //     bool isPalindrome(string str){
        
// //         int n = str.size();
// //         for(int i=0,j=n-1;i<j; i++,j--){
// //             if(str[i]!=str[j]) return 0;
// //         }
// //         return 1;
// //     }
};


//  TRICKY LOGIC
// class Solution {
// public:
//     int countSubstrings(string s) {
//         int n = s.size();
//         int cnt = 0;
//         for(int i = 0; i < n; i++) {
//             palindromic(s, i, i, cnt);  //judge odd substring
//             palindromic(s, i, i+1, cnt);//judge even substring
//         }
//         return cnt;
//     }
    
// private:
//     void palindromic(string s, int left, int right, int& cnt) { //judge if a substring is palindromic
//         while(left >=0 && right < s.size() && s[left] == s[right]) {
//             cnt++;
//             left--;
//             right++;
//         }
//     }
// };