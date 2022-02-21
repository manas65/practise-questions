// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    
    int helper(int w, int wt[], int val[], int n, vector<vector<int>>&dp, int idx){
        if(w==0 || idx==n){
            return dp[w][idx]=0;
        }
        if(dp[w][idx]!=-1)return dp[w][idx];
        int ans=-1e8;
        if(w-wt[idx]>=0)ans=max(ans,helper(w-wt[idx],wt,val,n,dp,idx+1)+val[idx]);
        ans=max(ans,helper(w,wt,val,n,dp,idx+1));
        return dp[w][idx]=ans;
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
        return helper(W,wt,val,n,dp,0);
       // Your code here
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends