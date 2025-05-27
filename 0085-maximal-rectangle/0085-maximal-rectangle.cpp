class Solution {
public:
    int maximalRectangle(vector<vector<char>>& arr) {
        vector<int> hist(arr[0].size(), 0);
        int cols = arr[0].size();
        int rows = arr.size();

        int maxArea = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (arr[row][col] == '1') hist[col] += 1;
                else hist[col] = 0;
            }
            int area = largestAreaInHistogram(hist);
            maxArea= max(maxArea, area);
        }

        return maxArea;
    }

    int largestAreaInHistogram(vector<int>& hist) {

        int maxArea = 0;

        for (int i = 0; i < hist.size(); i++) {

            int left = i-1;
            int right = i+1;
            int lwidth = 0;
            int rwidth = 0;
            while (left >= 0 and hist[left] >= hist[i]) {
                lwidth++;
                left--;
            }
            while (right < hist.size() and hist[right] >= hist[i]) {
                rwidth++;
                right++;
            }
            int width = lwidth + rwidth + 1;
            cout<<"lwidth:"<<lwidth<<","<<"rwidth"<<rwidth<<","<<"Aread:"<<width * hist[i]<<"-";
            maxArea = max(maxArea, width * hist[i]);
        }
        return maxArea;
    }
};