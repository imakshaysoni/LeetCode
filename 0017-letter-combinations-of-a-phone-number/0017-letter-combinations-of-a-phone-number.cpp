class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string>m;
        vector<string> ans;
        
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        string subset;
        helper(digits, m, ans, subset, 0);
        
        return ans;
        
        
    }
    
    void helper(string digits, unordered_map<char, string> &m, vector<string> &ans, string subset, int i){
        
        
        if(digits.size()==0) return;
        
        if(subset.size()==digits.size()) {
            ans.push_back(subset);
            return;
        }  
        // if(i>=s.size()) return;
        
        string temp = m[digits[i]];
        for(int j=0;j<temp.size();j++){
            subset.push_back(temp[j]);
            helper(digits,m,ans,subset,i+1);
            subset.pop_back();
        }
        
    }
};