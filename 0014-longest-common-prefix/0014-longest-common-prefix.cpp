class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end());
        int n = strs[0].size();
        int n1 = strs.size();
        string ans = "";
        for(int i=0;i<n;i++){
            int j;
            for(j=0;j<n1;j++){
                if(strs[j][i]!=strs[0][i]) break;
            }
            if(j==n1) ans+=strs[0][i];
            else break;

        }
        return ans;
        
    }
};