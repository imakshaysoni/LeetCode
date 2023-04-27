class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        
        
        int maxProd = 1;
        int minProd = 1;
        int ans = INT_MIN;
        for(int num: nums){
            if(num<0) swap(maxProd,minProd);
            
            maxProd = max(num,maxProd*num);
            minProd = min(num, minProd*num);
            
            ans = max(maxProd,ans);
            
            
        }
        
        return ans;
        
        
        
    }
};