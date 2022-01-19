class Solution {
public:
    int helper(vector<int>& coins, int amount, int idx,vector<vector<int>>&dp ){
        if(amount==0)return dp[idx][amount]=0;
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        int ans=1e8;
        for(int i=idx;i<coins.size();i++)
            if(amount-coins[i]>=0)
                ans=min(ans,helper(coins,amount-coins[i],idx,dp));
        
       return dp[idx][amount]=ans+1;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
    
    int ans=helper(coins,amount,0,dp);
        return ans>1e8?-1:ans;
    }
    
};