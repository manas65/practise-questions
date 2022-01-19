class Solution {
public:
    int ways(int amount, vector<int>& coins, int idx,vector<vector<int>>&dp){
        if(amount==0)return dp[idx][amount]=1;
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        int ans=0;
        
        for(int i=idx;i<coins.size();i++)
            if(amount-coins[i]>=0)
                ans+=ways(amount-coins[i],coins,i,dp);
        return dp[idx][amount]= ans;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return ways(amount,coins,0,dp);
    }
};