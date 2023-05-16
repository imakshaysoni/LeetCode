class Solution {
public:
    bool isValid(string s) {
    unordered_map<char, char> m;
        m[')'] = '(';
        m['}'] = '{';
        m[']'] = '[';
        
        stack<char> st;
        for(auto ch : s){
            if(ch == '{' || ch == '(' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.empty() || st.top() != m[ch]) return false;
                st.pop();
            }
            
            
        }
        if(st.empty()) return true;
        return false;
    }
};