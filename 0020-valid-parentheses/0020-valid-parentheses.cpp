class Solution {
public:
    bool isValid(string s) {



        return mysol(s);
    }
    bool mysol(string s){
        unordered_map<char, char> mapp = { 
    {'}', '{'},
    {')', '('}, 
    {']', '['}
};
        stack<char> st;

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(mapp.find(ch)!=mapp.end()){
                // Its a closing brack
                if(st.empty() || st.top() != mapp[ch]) return false;
                st.pop();
            }
            else{
                st.push(ch);
            }    
        }
        return st.empty();
    }
};