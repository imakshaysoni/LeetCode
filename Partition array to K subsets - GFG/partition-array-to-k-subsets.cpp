//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
        
        if(k>n) return false;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        
        if(sum%k!=0 || k > sum) return false;
        
        int target = sum/k;
        vector<int> buckets(k,0);
        return helper(a,n,k,buckets, 0, target);
        
        
         //Your code here
    }
    
    
    bool helper(int a[], int n, int k, vector<int> &buckets, int index, int target){
        
        
        if(index==n){
            for(auto sum: buckets){
                if(sum!=target) return false;
            }
            return true;
        }
        
        for(int i=0;i<k;i++){
            
            if(buckets[i]+a[index] > target) continue;
            buckets[i]+=a[index];
            
            if(helper(a,n,k,buckets,index+1, target)) return true;
            
            buckets[i]-=a[index];
            
            if(buckets[i]==0) break;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends