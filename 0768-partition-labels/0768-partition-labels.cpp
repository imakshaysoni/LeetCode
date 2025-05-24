class Solution {
public:
    static bool comp(vector<int> a, vector<int> b) { return a[0] < b[0]; }
    vector<int> mergeIntervals(vector<vector<int>> intervals) {
        vector<vector<int>> result;
        for (auto it : intervals) {
            if (result.empty() || it[0] > result.back()[1]) {
                result.push_back(it);
            } else {
                result.back()[1] = max(it[1], result.back()[1]);
            }
        }
        cout << endl;
        for (auto it : result) {
            for (auto val : it)
                cout << val << ",";
            cout << endl;
        }

        vector<int> ans;
        for (auto it : result) {
            if (it[1] == -1)
                ans.push_back(1);
            else
                ans.push_back(it[1] - it[0] + 1);
        }
        return ans;
    }

    vector<int> two_pointer(string s){

        vector<int> mapp(26, 0);
        for(int i=0;i<s.size();i++){
            mapp[s[i]-'a'] = i; // Store last index of each char
        }
        vector<int> ans;
        int start = 0;
        int end = -1;
        int i = 0;
        while(i<s.size()){

            end = max(end, mapp[s[i]-'a']);

            if(i==end){
                ans.push_back(end-start+1);
                start = i+1;
            }
            i++;



        }
        return ans;




    }

    vector<int> partitionLabels(string s) {

        return two_pointer(s);

        unordered_map<char, pair<int, int>> mapp;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (mapp.find(ch) == mapp.end()) {
                mapp[ch] = {i, -1};
            } else {
                mapp[ch].second = i;
            }
        }
        vector<vector<int>> intervals;
        for (auto it : mapp) {
            intervals.push_back({it.second.first, it.second.second});
        }
        sort(intervals.begin(), intervals.end(), comp);

        for (auto it : intervals) {
            for (auto val : it)
                cout << val << ",";
            cout << endl;
        }

        return mergeIntervals(intervals);
    }
};