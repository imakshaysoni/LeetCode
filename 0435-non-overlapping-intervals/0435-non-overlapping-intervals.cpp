class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        if(a[1]<b[1]) return true;
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int end= intervals[0][1];
        int count = 0;
        for(int i=1;i<intervals.size();i++){
            if(end>intervals[i][0]) count++;
            else end=intervals[i][1];
        }
        return count;
    }
};