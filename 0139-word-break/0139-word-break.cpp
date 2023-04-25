class Solution{
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        if(wordDict.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))
                                                    != wordDict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
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