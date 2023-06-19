class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int> (m,INT_MAX));
        queue<pair<int, pair<int,int>>> q;
        int final_ans=INT_MAX;
        q.push({0, {0,0}});
        dist[0][0]=0;
        while(!q.empty()){
            int diff = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();
            if(i==n-1 && j==m-1) {
                            final_ans = min(final_ans, diff);
                        }
            for(int delrow=-1; delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int new_i = i + delrow;
                    int new_j = j + delcol;
                    if(abs(delrow)!= abs(delcol) && new_i>=0 && new_j>=0 && new_i<heights.size() && new_j<heights[0].size())
                    {
                        int new_diff = max(diff, abs(heights[i][j]-heights[new_i][new_j]));
                        if(new_diff < dist[new_i][new_j]){
                            dist[new_i][new_j]=new_diff;
                            q.push({new_diff, {new_i,new_j}});
                        }                        
                    }                    
                }
            }            
        }
        return final_ans;
    }
};