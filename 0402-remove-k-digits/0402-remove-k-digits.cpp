class Solution {
public:
    string removeKdigits(string num, int k) {
        
        
        
        
        string ans="";
        for(char &c:num)
        {
            while(ans.size() && ans.back()>c &&k)
            {
                ans.pop_back();
                k--;
            }
            if(ans.size()||c!='0')ans.push_back(c);
        }
        while(ans.size()&&k--)           //<-------this look is to make sure we fulfil the deletion condition
        {
            ans.pop_back();
        }
        return (ans=="")?"0":ans;
        
        
        
        
        
        
        
        
        
//         if(num.size()==k) return "0";
//         stack<int> st;
//         string s;
//         int i=0;
//         for(char ch: num){
            
//             while(!st.empty() and k>0 and st.top() > ch-'0'){
//                 st.pop();
//                 k--;
//             }
//             st.push(ch-'0');
//             if(st.size()==1 and st.top()==0) st.pop();
            
//         }
        
//     while(k and !st.empty()){
        
//     st.pop(); k--;
//     }
//     if(st.empty()) return "0";
//     while(!st.empty()){
//         s += to_string(st.top());
//         st.pop();
//     }
        
//         reverse(s.begin(),s.end());
//         return s;
        
    }
};