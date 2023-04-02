class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int min=intervals[0][0];
        int max=intervals[0][1];
        vector<vector<int>> v;
        vector<int> r(2);
        for(int i=1;i<intervals.size();i++){
            if(max>=intervals[i][0]){
                if (intervals[i][1]>max)max=intervals[i][1];
            }
            else{
                
                r[0]=min;
                r[1]=max;
                v.push_back(r);
                min=intervals[i][0];
                max=intervals[i][1];
            }
            
        }
       r[0]=min;
        r[1]=max;
        v.push_back(r);
        return v;
    }
};