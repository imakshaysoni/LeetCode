class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int j=height.size()-1;
        int i=0;
        int sum=INT_MIN;
        while(i<j){
            
            sum=max(sum,min(height[i],height[j])*(j-i));
            if(height[i]<height[j])i++;
            else j--;
            
        }
        return sum;
        
    }
};