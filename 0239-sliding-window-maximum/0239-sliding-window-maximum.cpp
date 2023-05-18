class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {  
        // TC: O(N) + O(N){poping elemnet from queue} SC: O(K) (At Max only k element get stoed in deque)
        deque<int> q;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if (!q.empty() and q.front() < i-k+1) q.pop_front(); //Out of bound
            while(!q.empty() and nums[q.back()] <= nums[i]){ //Storing Smaller Element does not making any sense
                q.pop_back();
            }
            q.push_back(i);
            if(i>=k-1){ // Starts from first window
                ans.push_back(nums[q.front()]);
            }
            
            
        }
        
        return ans;
    
        
        
        
        
//         Brute FOrce TLE
    //     stack<int> st;
    //     vector<int> v;
    //     int maxx=INT_MIN;
    //     for(int i=0;i<=nums.size()-k;i++){
    //         int temp = 0;
    //         while(temp<k and i+temp<nums.size()){
    //             maxx = max(maxx,nums[i+temp]);
    //             temp++;                
    //         }
    //         v.push_back(maxx);          
    //         maxx=INT_MIN;
    //     }
    // return v;
        
    }
};