class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;
        if(n==1) return true;
        
        priority_queue<int, vector<int>, greater<int> > pq;
        unordered_map<int,int> mapp;
        for(auto it: hand){
            mapp[it]++;
        }
        for(auto it: mapp) pq.push(it.first);
        
        while(!pq.empty()){
            int mini = pq.top(); pq.pop();
            if(mapp[mini]<=0) continue;
            mapp[mini]--;
            for(int i=1;i<groupSize;i++){
                if(mapp[mini+i]<=0) return false;
                mapp[mini+i]--;
            }
            if(mapp[mini]>0) pq.push(mini);
        }
        return true;
        
    }
};