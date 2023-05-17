class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
     
        vector<int> ans;
        stack<int> st;
        stack<int> s2;
        
        for(int x: asteroids){
            if(st.empty() || x>0) st.push(x);
            else
            {
                    while(!st.empty() and st.top()>0 and st.top() < abs(x)){
                        st.pop();                        
                    }
                    if(!st.empty() and st.top()>0 and st.top() == abs(x) ){
                        st.pop();
                    }
                    else if (!st.empty() and st.top() < 0 and x < 0) {
                            st.push(x);
                    }
                    else if(st.empty()) st.push(x);
                    
            }
        }
        
        if(st.empty())
        { 
            return ans;
        }
        else{
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
};