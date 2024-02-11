class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> left;
        stack<int> star;
        
        for(int i=0;i<s.size();i++) 
        {
            char ch = s[i];
            if(ch=='(') left.push(i);
            else if(ch=='*') star.push(i);
            else{
                if(!left.empty()) left.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        
        while(left.size()>0){
            if(star.size()==0) return false;
            if(star.top()>left.top()){
                star.pop();
                left.pop();
            }
            else return false;
        }
        
        return true;
        
        
    }
};