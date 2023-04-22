//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        
        int sum =0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return 0;
        int target = sum/2;
        vector<vector<int>> dp(N, vector<int> (target+1, -1));
        return helper(arr, target, 0, dp, N);
        
        
        
    }
    
    bool helper(int nums[], int target, int i, vector<vector<int>> &dp, int N){
        
        
        if(i>=N || target < 0) return false;
        if(target==0) return true;
        
        if(dp[i][target]!=-1) return dp[i][target];
        
        
//         Take one element
        bool op1 = helper(nums, target-nums[i], i+1, dp, N);
        bool op2 = helper(nums, target, i+1, dp, N);
        dp[i][target] = op1 || op2;
        return dp[i][target];
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends