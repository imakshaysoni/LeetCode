class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans="";
        int start=0;
        int count=0;
        for(int i=0;i<n ;i++){
            if(s[i]=='(')
            { 
                if(count==0) start=i;
                count++;
            }
            else count--;
            if(count==0){
                start=start+1;
                while(start<i){
                    ans += s[start];
                    start++;
                }
            }
        }
        return ans;
        
    }
};