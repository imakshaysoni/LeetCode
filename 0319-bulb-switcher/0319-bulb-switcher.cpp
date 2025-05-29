class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
        if(n==1 or n==0) return n;
        vector<int> bulbs(n+1, 1);
        // first round
        //second round
        for(int i=2;i<=n;i+=2){
            bulbs[i] = 0;
        }

        // from third round to nth round
        int count = 0; //bulbs[1];
        for(int round=3;round<=n; round++){
            for(int i=round;i<sqrt(n);i+=round){
                bulbs[i] = !bulbs[i];
            }
        }
        int cnt =0;
        for(int i=1;i<=n;i++){
            if(bulbs[i]) cnt++;
        }
        return cnt;


        
        // vector<int> bulbs(n+1, 1);
        // for(int i=2;i<=n;i+=2){
        //     bulbs[i] = 0;
        // }
        // for(int round=3;round<=n;round++){
        //     for(int i=round;i<=n;i+=round){
        //         bulbs[i] = !bulbs[i];
        //     }
        // }
        
        // int count =0;
        // for(int i=1;i<=n;i++){
        //     if(bulbs[i]) count++;
        // }
        // return count;
    }
};