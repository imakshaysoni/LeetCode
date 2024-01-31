class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
        if(i.size()==1) return i;
        
        vector<vector<int>> ans;
        sort(i.begin(), i.end());
        int minn = i[0][0];
        int maxx = i[0][1];
        
        for(int j=1;j<i.size();j++){
            
            int curr_minn = i[j][0];
            int curr_maxx = i[j][1];
            if(curr_minn <= maxx){
                minn = min(minn, curr_minn);
                maxx = max(maxx, curr_maxx);
                // ans.push_back({minn, maxx});
            }
            else{                                
                ans.push_back({minn, maxx});
                minn = curr_minn;
                maxx = curr_maxx;
            }
        }
        ans.push_back({minn,maxx});
        return ans;
        
    }
};