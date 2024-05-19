class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        
        unordered_map<char,int> mapp;
        for(auto it: tasks) mapp[it]++;
        
        for(auto it: mapp){
            pq.push(it.second);
        }
        
        int count = 0;
        int time = 1;
        while(!pq.empty() || !q.empty()){
            if(!pq.empty()){
                int task = pq.top(); pq.pop();
                task -=1;
                if(task>0) q.push({task,time+n});
            }
            if(!q.empty() and q.front().second == time){
                auto it = q.front();
                pq.push(it.first);
                q.pop();
            }
            time++;
            count++;
        }
        
        return count;
        
        
    }
};