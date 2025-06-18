class Solution {
public:
    int totalHours(vector<int> &piles, int k){

        int totalH = 0;
        for(int i=0;i<piles.size();i++){
            int h = ceil(piles[i]/double(k));
            if(totalH > INT_MAX - h) return INT_MAX;
            totalH += h;
        }
        return totalH;


    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for(int i=0;i<piles.size();i++){
            maxi =max(maxi, piles[i]);
        }

        int low=1;
        int high = maxi;
        int ans = INT_MAX;

        while(low<=high){
            int k = low+(high-low)/2;
            
            int totalH = totalHours(piles, k);
            if(totalH <= h){
                ans = min(ans, k);
                high = k-1;
            }
            else{
                low = k+1;
            }

        }
        return ans;

        
    }
};