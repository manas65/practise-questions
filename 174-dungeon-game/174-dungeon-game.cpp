class Solution {
public:
    
    int helper(int si,int sc, int ei, int ec,vector<vector<int>>& dungeon,vector<vector<int>>& dp){
        if(si==ei && sc==ec)return (dungeon[si][sc]<=0)?-dungeon[si][sc]+1:1;//if neg hai to survive krna ka liya -neg health +1 otherwise just 1 health is required;
        
        if(dp[si][sc]!=-1)return dp[si][sc];
        int ans=1e8;
        if(si+1<=ei)ans=min(ans,helper(si+1,sc,ei,ec,dungeon,dp));
        if(sc+1<=ec)ans=min(ans,helper(si,sc+1,ei,ec,dungeon,dp));
        
        ans-=dungeon[si][sc];
        if(ans<=0)ans=1;//current position pai min health required to survive is negative but min value must be 1, iska meaning hai current grid pai value left aur down sai zada thi
        
        return dp[si][sc]=ans;
    }
    
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
     //har point pai survive ka liya how much health   
        int n=dungeon.size(),m=dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return helper(0,0,n-1,m-1,dungeon,dp);
    }
};