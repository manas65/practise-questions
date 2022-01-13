class Solution {
public://dp sol,dp(idx,count)=
            //if open  dp(idx+1,count+1)
            //else if close dp(idx+1,count-1)
            //else * 3 cases open,close,none ke sath match 
  
    int dfs(string &s,int idx, int count,vector<vector<int>>& dp){
     
        
        if(count<0)return 0;
        if(idx==s.size()){
            if(count==0)return dp[idx][count]=1;
            return dp[idx][count]=0;
        }
        if(dp[idx][count]!=-1)return dp[idx][count];
        
        if(s[idx]=='(')return dp[idx][count]=dfs(s,idx+1,count+1,dp);
        else if(s[idx]==')')return dp[idx][count]=dfs(s,idx+1,count-1,dp);
        
        //* case
        return dp[idx][count]=dfs(s,idx+1,count+1,dp) || dfs(s,idx+1,count-1,dp)||dfs(s,idx+1,count,dp);
        
    }
    
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,-1));
        int ans= dfs(s,0,0,dp);
        if(ans==0)return false;
        return true;
    }
};