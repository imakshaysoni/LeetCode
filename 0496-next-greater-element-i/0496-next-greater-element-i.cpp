class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size()-1;
        stack<int> s;
        unordered_map<int, int> arr;
        arr[nums2[n2]] = -1;
        s.push(nums2[n2]);
        for(int i=n2-1;i>=0;i--){
            int curr = nums2[i];
            while(!s.empty() and s.top() < curr) s.pop();            
            if(s.empty()) arr[curr] = -1;
            else arr[curr] = s.top();
            s.push(curr);
        }
        
        vector<int> ans;
        for(int x: nums1){
            ans.push_back(arr[x]);
        }
        
        
        
        return ans;
    }
};