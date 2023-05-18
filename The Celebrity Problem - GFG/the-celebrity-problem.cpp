//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int row = M.size();
        int col = M[0].size();
        vector<int> poc;
        // Find the person who might be celebrity
        for(int i=0;i<row;i++){
            int j=0;
            while(j<col){
                if(M[i][j]!=0) break;
                j++;
            }
            if(j==col) poc.push_back(i);
        }
        if(poc.size()==row or poc.size()==0) return -1;
        // for(int a: poc) cout<<a<<" ";
        // if(poc.size()==row) return -1;
        for(int x: poc){
            int i=0;
            for(;i<row;i++){
                if(i==x) continue;
                if(M[i][x]==0) break;
            }
            // cout<<i<<"->"<<row<<endl;
            if(i==row) return x;
        }
        
        return -1;
        
        
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends