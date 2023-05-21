class Solution {
public:
    vector<int> getPrevious(vector<int>&nums, bool isPrevSmall)
    {
        //(isPrevSmall = true) ===> previous smaller element problem using stack
        //(isPrevSmall = false) ==> previous greater element problem using stack
        //There could me many ways to solve this using monotonic stack, simpler way shown below
        int n = nums.size();
        stack<int>st;
        vector<int>ans(n, -1);
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            int curr = nums[i];
            //============================================
            while(!st.empty())
            {
                bool condition = (isPrevSmall)? (curr < nums[st.top()]) : (curr > nums[st.top()]);
                if (condition == true)
                {
                    ans[st.top()] = i;
                    st.pop();
                }
                else break;
            }
            //=================================================
            st.push(i);
        }
        return ans;    
    }
    vector<int> getNext(vector<int>&nums, bool isNextSmall)
    {
        //(isPrevSmall = true) ===> next smaller/equal element problem using stack
        //(isPrevSmall = false) ==> next smaller/equal element problem using stack
        int n = nums.size();
        vector<int>ans(n, n);
        stack<int>st;
        st.push(0);
        for (int i = 1; i < n; i++)
        {
            int curr = nums[i];
            //======================================
            while(!st.empty())
            {
                int topIdx = st.top();
                bool condition = (isNextSmall)? (curr <= nums[topIdx]) : (curr >= nums[topIdx]);
				//DON'T MISS THE "EQUAL TO" CASE :)
                if (condition == true)
                {
                    ans[topIdx] = i;
                    st.pop();
                }
                else break;
            }
            //===================================================
            st.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>prevSmaller = getPrevious(nums, true);
        vector<int>prevGreater = getPrevious(nums, false);
        //===================================================
        vector<int>nextSmaller = getNext(nums, true);
        vector<int>nextGreater = getNext(nums, false);
        //=======================================================
        
        cout<<"NextGreater: ";
        for(auto x: nextGreater) cout<<x<<" ";
        cout<<endl;
        cout<<"NextSmaller: ";
        for(auto x: nextSmaller) cout<<x<<" ";
        cout<<endl;
        cout<<"prevGreater: ";
        for(auto x: prevGreater) cout<<x<<" ";
        cout<<endl;
        cout<<"prevSmaller: ";
        for(auto x: prevSmaller) cout<<x<<" ";
        cout<<endl;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            
            int prevRangeCount1 = i - prevGreater[i];
            int nextRangeCount1 = nextGreater[i] - i;
            long long maxSubarrayCount = prevRangeCount1 * nextRangeCount1;
            long long mini = (long long)(nums[i] * maxSubarrayCount);
            // ans = ans + (long long)(nums[i] * maxSubarrayCount);
            
            
            int prevRangeCount = i - prevSmaller[i];
            int nextRangeCount = nextSmaller[i] - i;
            long long minSubarrayCount = (long long)prevRangeCount * nextRangeCount;
            long long maxi = (long long)(nums[i] * minSubarrayCount);
            // ans = ans - (long long)(nums[i] * minSubarrayCount);
            ans +=  maxi-mini;
        }
        return abs(ans);
    }
};