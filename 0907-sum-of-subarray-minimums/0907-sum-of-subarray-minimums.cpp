class Solution {
public:
    int sum=0;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevSmaller(n);
        vector<int> nextSmaller(n);
        stack<int> s;
//         Left: PrevSmaller
        for(int i=0;i<n;i++){
            int curr = arr[i];
            while(!s.empty() and arr[s.top()] >= curr ) s.pop();
            
            if(s.empty()) prevSmaller[i] = -1;
            else prevSmaller[i] = s.top();
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        //         right: nextSmaller
        for(int i=n-1;i>=0;i--){
            int curr = arr[i];
            while(!s.empty() and arr[s.top()] > curr ) s.pop();
            
            if(s.empty()) nextSmaller[i] = n;
            else nextSmaller[i] = s.top();
            s.push(i);
        }
        
        
        int modulo = 1000000007;
        // for(int x: prevSmaller) cout<<x<<" ";
        // cout<<endl;
        // for(int x: nextSmaller) cout<<x<<" ";
    
        for(int i=0;i<n;i++){         
           sum = (sum + ((long long)arr[i] * (i - prevSmaller[i]) * (nextSmaller[i] - i)) % modulo) % modulo;
        }      
        
     
    return sum;   
        
    }
    
};