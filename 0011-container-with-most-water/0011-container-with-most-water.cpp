class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int left= 0;
        int right = n-1;
        int maxi = 0;
        while(left<right){
            if(height[left] < height[right]){
                maxi = max(maxi, height[left]*(right-left));
                left++;
            }
            else{
                maxi = max(maxi, height[right]*(right-left));
                right--;
            }

        }
        return maxi;


        
    }
};