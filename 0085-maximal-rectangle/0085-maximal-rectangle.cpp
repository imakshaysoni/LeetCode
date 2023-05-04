class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea=INT_MIN;
        vector<int> heights(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            int area = largestRectangleArea(heights);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        int maxArea=0;
        int n = heights.size();
        vector<int> next;
        vector<int> prev;
        next = nextSmaller(heights);
        prev = prevSmaller(heights);
        // for(int x: next) cout<<x<<" ";
        // for(int y: prev) cout<<y<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++){
            if(next[i] == -1) next[i]=n;
            int area = (next[i]-prev[i]-1) * heights[i];
            maxArea = max(area, maxArea);
        }
        
        return maxArea;
    }
    
    vector<int> nextSmaller(vector<int> &heights){
        int n = heights.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        
        for(int i=n-1;i>=0;i--){
            int currVal = heights[i];
            while(s.top()!=-1 and heights[s.top()] >= currVal){
                s.pop();
            }
            ans[i]= s.top();
            s.push(i);            
            
        }
        return ans;
    }
    
    vector<int> prevSmaller(vector<int> &heights){
        int n = heights.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        
        for(int i=0;i<n;i++){
            int currVal = heights[i];
            while(s.top() !=-1 and heights[s.top()] >= currVal){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);            
            
        }
        return ans;
    }
    
};


// class Solution {
// public:
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int maxi=0;
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if(matrix[i][j]=='1'){
//                     int ans = helper(matrix, i, j);
//                     cout<<ans<<endl;
//                     maxi = max(maxi, ans);
//                 }
//             }
//         }
        
//         return maxi;
//     }
    
//     int helper(vector<vector<char>> &mat, int i, int j){
        
//         if(i>=mat.size() || j>=mat[0].size() || mat[i][j]=='0') return 0;
        
//         int op1 = helper(mat, i, j+1);
//         int op2 = helper(mat, i+1, j);
        
//         return 1+max(op1, op2);
        
        
//     }
// };