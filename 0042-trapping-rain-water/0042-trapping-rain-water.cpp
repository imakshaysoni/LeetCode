class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        int lmax=0;
        for(int i=0;i<n;i++){
            lmax= max(lmax, height[i]);
            leftMax[i] = lmax;
        }
        int rMax=0;
        for(int i=n-1;i>=0;i--){
            rMax = max(rMax, height[i]);
            rightMax[i] = rMax;
        }
        int water = 0;
        for(int i=0;i<n;i++){
            water += min(rightMax[i], leftMax[i]) - height[i];
        }
        return water;
        
    }
};