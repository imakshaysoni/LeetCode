class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        map<int, int> mapper;
        for(auto it: hand){
            if(mapper.find(it)!=mapper.end()){
                mapper[it] += 1;
            }
            else mapper[it] = 1;
        }

        while(!mapper.empty()){
            int curr = mapper.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mapper[curr+i]==0) return false;
                
                mapper[curr+i]--;

                if(mapper[curr+i]==0) mapper.erase(curr+i);
            }
        }
        return true;

    }
};
