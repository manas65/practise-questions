class Solution {
public:
    int helper(int n, vector<int>&dp){
        if(n==0)return dp[n]=1;
        if(dp[n]!=-1)return dp[n];
        int ans=1;
        for(int i=1;i<n;i++){
            if(n-i>=0)
                ans=max({ans,helper(n-i,dp)*i,(n-i)*i});
        }
        return dp[n]=ans;
        
    }
    
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};