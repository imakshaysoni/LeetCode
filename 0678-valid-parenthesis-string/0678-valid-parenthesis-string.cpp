class Solution {
public:
    bool checkValidString(string s) {
        
        stack<char> open;
        stack<char> star;

        for (int i=0;i<s.size();i++){
            char ch  = s[i];

            if(ch=='(') open.push(i);
            else if(ch=='*') star.push(i);
            else{
                if(open.size()>0) open.pop();
                else if(star.size()>0) star.pop();
                else return false;
            }
        
        }
        while(open.size()>0){
            if(star.size()==0) return false;
            if(star.top() > open.top()) {
                open.pop();
                star.pop();
            }
            else return false;
        }
        return true;
    }
};