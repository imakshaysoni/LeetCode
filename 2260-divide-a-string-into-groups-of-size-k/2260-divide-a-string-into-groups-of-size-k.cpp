class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int i = 0;
        while(i < s.size()){
            string ch = "";
            for(int j=i;j<i+k and j<s.size();j++){
                ch += s[j];
            }
            if(ch.size()<k){
                ch += string(k - ch.size(), fill);
            }
            ans.push_back(ch);
            i+=k;

        }
        return ans;
        
    }
};