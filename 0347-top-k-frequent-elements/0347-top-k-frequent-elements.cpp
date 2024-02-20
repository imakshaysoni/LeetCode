class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mapp;
        
        for(int i=0;i<nums.size();i++){
            mapp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>> pq;
        for(auto it: mapp){
            pq.push({it.second, it.first});
        }
        
        vector<int> ans;
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};