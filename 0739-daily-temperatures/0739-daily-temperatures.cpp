class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()) result[i]=0;
            else{
                while(!st.empty()){
                    auto top = st.top();
                    if(top.first>temperatures[i]){
                        result[i] = (top.second-i);
                        break;
                    }
                    st.pop();
                }
            }
            st.push({temperatures[i], i});
        }
        return result;
    }
};
