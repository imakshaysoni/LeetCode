//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int nums[], int n) {
        // code here
        if(n<=2) return n; 
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans, 2 + solve(j,nums[j]-nums[i],nums, n));
            }
        }
        
        return ans;
        
    }
    
    int solve(int index, int diff, int nums[], int n){
        
        int ans = 0;
        for(int j=index+1;j<n;j++){
            if(nums[j]-nums[index]==diff){
                ans = max(ans, 1 + solve(j, diff, nums,n));
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends