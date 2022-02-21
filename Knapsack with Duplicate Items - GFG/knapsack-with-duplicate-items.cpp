// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
         int helper(int w, int wt[], int val[], int n, vector<vector<int>>&dp, int idx){
        if(w==0 || idx==n){
            return dp[w][idx]=0;
        }
        if(dp[w][idx]!=-1)return dp[w][idx];
        int ans=-1e8;
        if(w-wt[idx]>=0)ans=max(ans,helper(w-wt[idx],wt,val,n,dp,idx)+val[idx]);
        ans=max(ans,helper(w,wt,val,n,dp,idx+1));
        return dp[w][idx]=ans;
    }

    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
        return helper(W,wt,val,n,dp,0);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends