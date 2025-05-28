class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        return largestAreaInHistogram(heights, n);
        
    }

    vector<int> prev_smaller(vector<int> &hist){
        stack<int> st;
        vector<int> prevSmaller(hist.size(), -1);

        for(int i=0;i<hist.size();i++){
            while(!st.empty() and hist[st.top()] >= hist[i]){
                st.pop();
            }
            if(st.empty()) prevSmaller[i] = -1;
            if(!st.empty()) prevSmaller[i]=st.top();
            st.push(i);
        }
        return prevSmaller;
    }

    vector<int> next_smaller(vector<int> &hist){

        stack<int> st;
        vector<int> nextSmaller(hist.size(), -1);
        for(int i=hist.size()-1;i>=0;i--){
            while(!st.empty() and hist[st.top()]  >= hist[i]){
                st.pop();
            }
            if(st.empty()) nextSmaller[i] = hist.size();
            else nextSmaller[i] = st.top();
            st.push(i);
        }
        return nextSmaller;
    }

    int largestAreaInHistogram(vector<int>& hist, int n) {

        int maxArea = 0;
        vector<int> prevSmaller = prev_smaller(hist);
        vector<int> nextSmaller = next_smaller(hist);

        for (int i = 0; i < n; i++) {

            int leftIdx = prevSmaller[i];
            int rightIdx = nextSmaller[i];

            int width = rightIdx -leftIdx - 1;
            // if(i==2) cout<<leftIdx<<":"<<rightIdx<<endl;
            maxArea = max(maxArea, width * hist[i]);
        }
        return maxArea;
    }
};