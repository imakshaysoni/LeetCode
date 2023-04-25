class Solution{
public:
    bool wordBreak(string s, vector<string> &wordDict) {
    vector<int> dp(301,-1);
    return helper(s,wordDict, 0, dp);
    
    }
    
    bool helper(string &s, vector<string> &wordDict, int i, vector<int> &dp){
        
        if(i==s.size()) dp[i]=1;
        
        if(dp[i]!=-1) return dp[i];
        string temp;
        for(int k=i;k<s.size();k++){
            temp+=s[k];
            if (find(begin(wordDict), end(wordDict), temp) != end(wordDict)){
                if(helper(s,wordDict,k+1, dp)) {
                    dp[i]=1;
                    return dp[i];
            }            
            }
        }
        dp[i]=0;
        return dp[i];
    }
    
    

};
//  NOT WOKRING
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
        
        
//         string temp="";
//         for(int i=0;i<s.size(); i++){
//             temp+=s[i];
//             if(isInDict(temp, wordDict)) temp="";
            
//         }
//         if(temp=="") return true;
//         return false;        
        
//     }
    
//     bool isInDict(string &temp, vector<string> &wordDict){
//         cout<<temp<<endl;
//         if (find(begin(wordDict), end(wordDict), temp) != end(wordDict)){
//             cout<<"Found: "<<temp<<endl;
//             return true;  
//         } 
//         return false;
//     }
// };