class Solution {
public:
    /*
    let stone be a,b,c,d,c,e,f
    pick a,c=> a-c
    pick d=> d-(a-c)=>c+d-a
    pick e=>e-(c+d-a)=>a+e-(c+d)
    pick f=>f-(a+e-(c+d))=>f+c+d-(a+e)
    pick b=>b-(f+c+d-a-e)=>a+b+e -(c+d+f)
    we need to minimize this expression
    so problem boils down to min subset sum difference
    
    */
    
    int helper(vector<int>&v,int sum, int idx, vector<vector<int>>&dp){
        if(sum==0)return dp[idx][sum]= 1;
        if(idx>=v.size())return dp[idx][sum]= 0;
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        int ans=0;
        if(sum-v[idx]>=0)ans=ans || helper(v,sum-v[idx],idx+1,dp);
        ans=ans || helper(v,sum,idx+1,dp);
        
        return dp[idx][sum]=ans;
        
    }
    int lastStoneWeightII(vector<int>& stones) {
         int sum=0;
        for(int stone:stones)sum+=stone;
        int halfsum=sum/2;
        vector<vector<int>> dp(stones.size()+1,vector<int>(sum+1,-1));
        // helper(stones,sum,0,dp);
        int s1=0,s2=0;
        for(int i=0;i<=halfsum;i++){
            if(helper(stones,i,0,dp)){
                
            s2=max(s2,i);
            }
        }
        // cout<<endl;
        s1=sum-s2;
        return abs(s1-s2);
    }
};