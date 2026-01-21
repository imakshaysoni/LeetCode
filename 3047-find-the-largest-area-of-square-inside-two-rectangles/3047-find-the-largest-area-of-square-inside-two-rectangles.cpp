class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        
        int n = bottomLeft.size();
        int maxArea = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // topRight


                int x1 = min(topRight[i][0], topRight[j][0]);
                int x2 = max(bottomLeft[i][0], bottomLeft[j][0]);

                int y1 = min(topRight[i][1], topRight[j][1]);
                int y2 = max(bottomLeft[i][1], bottomLeft[j][1]);

                int w = x1-x2;
                int h = y1-y2;
                int min_hw = min(w,h);
                maxArea = max(maxArea, min_hw);        


            }
        }

        return 1LL * maxArea*maxArea;

    }
};