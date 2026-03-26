class Solution {
public:
    static bool comp(string s1, string s2){
        return s1.size() < s2.size();
    }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans = "";
        string firstStr = strs[0];
        string lastStr = strs[strs.size()-1];
        cout<<firstStr<<endl;
        cout<<lastStr<<endl;
        for(int i=0;i<firstStr.size();i++){
            if(firstStr[i]==lastStr[i]) ans+=firstStr[i];
            else break;
        }
        return ans;
    }
};