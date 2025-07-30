class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<int,int> mapp;
        for(char task: tasks){
            if(mapp.find(task)==mapp.end()){
                mapp[task]=1;
            }
            else{
                mapp[task]++;
            }
        }   
        priority_queue<int> pq;
        for(auto it: mapp){
            pq.push(it.second);
        }
        int time = 0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(pq.empty() and temp.empty()) return time;
                if(!pq.empty()){
                    int taskFreq = pq.top();
                    pq.pop();
                    taskFreq--;
                    if(taskFreq>0) temp.push_back(taskFreq);
                }
                time++;
            }
            for(auto val: temp){
                pq.push(val);
            }
        }
        return time;
    }
};