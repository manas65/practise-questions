class Solution {
public:
  //days ak dp bnado 
    int helper(int idx,vector<int>& costs, vector<int>&dp,unordered_set<int>& days){
        if(idx>365)return 0;
        if(dp[idx]!=-1)return dp[idx];
        
        int ans=1e8;
        if(days.find(idx)!=days.end()){
            ans=min({ans,helper(idx+1,costs,dp,days)+costs[0],helper(idx+7,costs,dp,days)+costs[1],helper(idx+30,costs,dp,days)+costs[2],});
        }
        else{
            ans=min(ans,helper(idx+1,costs,dp,days));
        }
        
        return dp[idx]=ans;
        
        
    }
    int mincostTickets(vector<int>& day, vector<int>& costs) {
        vector<int>dp(366,-1);
        unordered_set<int> days(day.begin(),day.end());
        return helper(0,costs,dp,days);
    }
};