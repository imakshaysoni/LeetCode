class Solution {
public:
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