// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int left=0,right=0,maxi=0;
//         int n =s.size();
//         // int cnt=0;
// //         LEft to Right
//         for(int i=0;i<n;i++){
//             if (s[i]=='(') left++;
//             else right++;
            
//             if (left==right) {
//                 maxi = max(maxi, left+right);
//             }
//             else if(right>left){
//                 left=right=0;
//             }
            
//         }
        
//         left=right=0;

//         //         right ot left
//         for(int i=n-1;i>=0;i--){
//             if(s[i]=='(') left++;
//             else right++;
            
//             if(left==right) {
//                 // cnt+=2;
//                 maxi = max(maxi, left+right);
//             }
//             else if(left>right){
//                 left=right=0;
//                 // cnt=0;
//             }
//         }
        
//         return maxi;
//     }
// };

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    ans = max(ans, i - stk.top());
                }
            }
        }
        return ans;
    }
};