class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        map<int, int> mapper;
        for(int i=0;i<hand.size();i++){

            if(mapper.find(hand[i])!=mapper.end()){
                mapper[hand[i]]+=1;
            }
            else{
                mapper[hand[i]] = 1;
            }
        }

        while(!mapper.empty()){

            int number = mapper.begin()->first;
            //1 -> 1, 2, 3 
            for(int i=0;i<groupSize;i++){
                if(mapper[number+i]==0) return false;

                mapper[number+i]--;
                if(mapper[number+i]==0) mapper.erase(number+i);

            }
        }

        return true;





    }
};