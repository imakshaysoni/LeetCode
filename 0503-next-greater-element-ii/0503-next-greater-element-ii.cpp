class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i=2*n-1;i>=0;i--){
            
            int curr = nums[i%n];
            while(!s.empty() and s.top() <= curr) s.pop();
            
            if (i < n) {
                  if (!s.empty()) ans[i] = s.top();
                  else ans[i]=-1;
            }
            s.push(curr);           
        }
        
        return ans;
        
    }
};