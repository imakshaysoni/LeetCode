class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> m;
        m['('] = ')';
        m['{'] = '}';
        m['['] = ']';
        if(s.size()%2!=0) return false;
        
        stack<char> stack;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack.push(s[i]);
            }
            else{
                if(stack.empty()) return false;
                char ch = stack.top();
                if(!stack.empty() && m[ch] == s[i]){
                    stack.pop();
                }
                else{
                    return false;
                }
                
                
            }
            
            
        }
        if(stack.empty()) return true;
        return false;
        
    }
};