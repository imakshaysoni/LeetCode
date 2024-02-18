class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
        vector<vector<int>> new_intervals;
        bool inserted=false;
        for(int i=0;i<n;i++){
            if(newInterval[0] < intervals[i][0] and inserted==false){
                new_intervals.push_back(newInterval);
                inserted=true;
            }
            new_intervals.push_back(intervals[i]);            
        }
        if(new_intervals.size()==intervals.size()) new_intervals.push_back(newInterval);
        vector<vector<int>> ans;
        int newn = new_intervals.size();
        for(int i=0;i<newn;i++){
            
            if(ans.empty() || new_intervals[i][0] > ans.back()[1]){
                ans.push_back(new_intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1] ,  new_intervals[i][1]);
            }
            
            
        }
        
        return ans;       
        
    }
};