class Solution {
public:

    vector<string> letterCombinations(string digits) {

        unordered_map<char, string> mapp = {
                                {'2', "abc"},
                                {'3', "def"},
                                {'4', "ghi"},
                                {'5', "jkl"},
                                {'6', "mno"},
                                {'7', "pqrs"},
                                {'8', "tuv"},
                                {'9', "wxyz"}
                            };
        vector<string> ans;
        string subset="";
        solve(digits, 0, mapp, ans, subset);
        return ans;
    }

    void solve(string &digit, int index, unordered_map<char, string> &mapp, vector<string> &ans, string subset){

            if(index >= digit.size()) {
                ans.push_back(subset);
                return;
            }

            string str = mapp[digit[index]];
            for(int i=0;i<str.size();i++){
                char ch = str[i];
                solve(digit, index+1, mapp, ans, subset + ch);
            }

            return;

    }

};