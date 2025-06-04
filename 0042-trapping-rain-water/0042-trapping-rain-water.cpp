class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        int lmax=0;
        int rmax = 0;
        for(int i=0;i<n;i++){
            lmax= max(lmax, height[i]);
            leftMax[i] = lmax;
            rmax = max(rmax, height[n-i-1]);
            rightMax[n-i-1] = rmax;
        }
        
        int water = 0;
        for(int i=0;i<n;i++){
            water += min(rightMax[i], leftMax[i]) - height[i];
        }
        return water;
        
    }
};