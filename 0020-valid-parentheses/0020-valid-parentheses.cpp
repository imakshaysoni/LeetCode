class Solution {
public:
    bool isValid(string s) {        
        stack<char> st;
        for(auto ch : s){
            if(ch == '{' || ch == '(' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;
                char it = st.top();
                if((ch==')' and it=='(') or (ch=='}' and it=='{') or (ch==']' and it=='[')) st.pop();
                else return false;
                
            }
            
            
        }
        return st.empty();
    }
};
