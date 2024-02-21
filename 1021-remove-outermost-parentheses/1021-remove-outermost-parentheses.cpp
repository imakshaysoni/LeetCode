class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string ans="";
        int open=0;
        for(char ch: s){
            if(ch=='('){
                if(open>0) ans+=ch;
                open++;
            }
            else{
                if(open>1) ans+=ch;
                open--;
            }
            
        }
        return ans;
        
    }
};