class Solution {
public:
    int jump(vector<int>& nums) {
	
        int currReach = 0;
        int maxReach = 0;
        int jumps=0;
        int n = nums.size();
        
        if(n<=1) return 0;
        if(nums[0]>=n-1) return 1;
        
        for(int i=0;i<n-1;i++){
            
            if(i+nums[i] > maxReach){
                maxReach = i+nums[i];
            }
            
            if(i==currReach){
                currReach = maxReach;
                jumps++;
            }
        
        }
        
        return jumps;
        
        
        
        // int position = nums.size() - 1;
	// int steps = 0;
	// while (position != 0) {
	// 	for (int i = 0; i < position; i++) {
	// 		if (nums[i] >= position - i) {
	// 			position = i;
	// 			steps++;
	// 			break;
	// 		}
	// 	}
	// }
	// return steps;
}
        
};