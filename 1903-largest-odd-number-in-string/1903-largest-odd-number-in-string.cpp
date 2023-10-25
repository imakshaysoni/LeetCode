class Solution {
public:
    string largestOddNumber(string nums) {
        int n = nums.size();
        string ans="";
        for(int i=n-1;i>=0;i--){
            if(int(nums[i])%2!=0){
                int k=0;
                while(k<=i){
                    ans += nums[k]; k++;
                }
                break;
            }
        }
        return ans;
        
    }
};