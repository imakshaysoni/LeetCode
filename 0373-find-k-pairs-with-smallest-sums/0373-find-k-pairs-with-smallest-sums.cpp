class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& A, vector<int>& B, int K) {
    		
        int n = A.size();
        int m = B.size();
        
        priority_queue< pair<int, pair<int,int> >, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;
        pq.push({A[0] + B[0], {0, 0}});

        set<pair<int,int>> st;
        st.insert({0,0});

        vector<vector<int>> ans;

        for(int i=0;i<K;i++){
            
            pair<int, pair<int,int> > ele = pq.top();
            pq.pop();           
            
            
            int idx1 = ele.second.first;
            int idx2 = ele.second.second;            
        
            ans.push_back({A[idx1], B[idx2]});    
            
            
            if(idx1+1 < n and st.find({idx1+1, idx2}) == st.end()){
                pq.push({A[idx1+1]+B[idx2], {idx1+1, idx2} });
                st.insert({idx1+1, idx2});
            }
            
            if(idx2+1 < m and st.find({idx1, idx2+1})==st.end()){                
                pq.push({A[idx1]+B[idx2+1], {idx1, idx2+1}});
                st.insert({idx1, idx2+1});
            }
            
        }
        
        return ans;
    }
};