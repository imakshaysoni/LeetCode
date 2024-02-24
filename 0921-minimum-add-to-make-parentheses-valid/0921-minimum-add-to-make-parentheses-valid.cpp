class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int open=0;
        for(char ch: s){
            if(ch=='(') st.push('(');
            if(ch==')'){
                if(!st.empty()) st.pop();
                else{
                   open++; 
                }
            }
        }
        return open+st.size();
    }
};