class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
        int base_color = image[sr][sc];
        helper(image, sr,sc, color, base_color);
        return image;
        
    }
    
    
    
    void helper(vector<vector<int>> & image, int sr, int sc, int color, int base_color){
        
        
        
        
        
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc]!=base_color || image[sr][sc]==color) return;
        
        
        image[sr][sc] = color;
        
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1, -1, 0, 0};
        for(int index=0;index<4;index++){
            helper(image, sr+dx[index], sc+dy[index], color, base_color);
        }
        
        return;
        
        
    }
};