class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        
        for(auto it: bills){
            if(it==5) five++;
            else if(it==10){
                ten++;
                five--;
            }
            else if(ten>0){
                ten--;
                five--;
            }
            else five-=3;
            if(five<0) return false;
        }
        return true;
        
    }
};