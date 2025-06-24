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
            while(ch.size()< k){
                ch += fill;
            }
            ans.push_back(ch);
            i+=k;

        }
        return ans;
        
    }
};