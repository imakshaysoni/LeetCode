//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> wordBreak(int n, vector<string>&dict, string s)
    {
        // code here
        unordered_set<string> set;
        for(auto x: dict) set.insert(x);
        
        string currStr = "";
        vector<string> result;
        helper(s, currStr, dict, 0, result, set);
        // for(auto x: result) cout<<x<<" ";
        return result;
        
    }
    
    void helper(string s, string currStr, vector<string> &dict, int index, vector<string>&result, unordered_set<string> &st){
        
        
        if(index == s.size()){
            currStr.pop_back();
            result.push_back(currStr);
            return;
        }
        
        string str="";
        for(int i=index;i<s.size();i++){
            str+=s[i];
            if(st.find(str)!=st.end()){                
                helper(s,currStr+str+" ", dict, i+1, result, st);
            }
        }
        
        return;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends