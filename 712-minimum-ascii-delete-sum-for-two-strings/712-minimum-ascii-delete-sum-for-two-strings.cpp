class Solution {
public:
    
    int helper(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
        
        if(i==s1.length() && j==s2.length())return 0;
        else if(i==s1.length()){
            int ans=0;
            while(j<s2.length())ans+=(int)s2[j++];
            return ans;
        }
           else if(j==s2.length()){
            int ans=0;
            while(i<s1.length())ans+=(int)s1[i++];
               return ans;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1e8;
        if(s1[i]==s2[j])ans=min(ans,helper(s1,s2,i+1,j+1,dp));
        else ans=min({ans,helper(s1,s2,i+1,j,dp)+(int)s1[i],helper(s1,s2,i,j+1,dp)+(int)s2[j]});
        
        return dp[i][j]=ans;
        
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(s1,s2,0,0,dp);
    }
};