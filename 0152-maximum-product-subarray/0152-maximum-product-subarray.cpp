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
        
        
//         for(int n: nums){
//             if(n>0){
//                 maxProd*=n;
//                 minProd=min(minProd*n,1);
//             }
//             if(n<0){
                
//                 int temp = maxProd;
//                 maxProd = max(1,minProd * n);
//                 minProd = temp*n;
//             }
//             if(n==0){ minProd=minProd=1;}
//             else ans = max(maxProd,ans);
//         }
//         return ans;
        
    }
};