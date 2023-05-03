class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> set;
        for(auto x: wordDict) set.insert(x);
        
        string currStr = "";
        vector<string> result;
        helper(s, currStr, wordDict, 0, result, set);
        
        return result;
        
    }
    
    void helper(string &s, string currStr, vector<string> &dict, int index, vector<string> &result, unordered_set<string> &st){
        
        
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