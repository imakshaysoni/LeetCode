class Solution {
public:
    char eval(vector<char> &vals, char op){


        if(op=='!') return vals[0]=='t' ? 'f' : 't';

        if(op=='&'){
            for(auto it: vals) {
                if (it=='f') return 'f';
            }
            return 't';
        }

        else{
            for(auto it: vals){
                if(it=='t') return 't';
            }
            return 'f';
        }
    }
    bool parseBoolExpr(string expression) {

        int n = expression.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            char ch = expression[i];
            if(ch==',') continue;
            
            if(ch!=')') st.push(ch);
            
            else
            {
                vector<char> vals;
                while(st.top() != '(') {
                    vals.push_back(st.top());
                    st.pop();
                } 

                // remove (
                st.pop();
                
                char op = st.top(); st.pop();
                char res = eval(vals, op);
                st.push(res);
            }
        }
        cout<<st.top();
        return st.top() == 't' ? true : false;
        
    }
};