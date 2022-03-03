class Solution {
public:
    int sum=0;
     int ap(vector<int>& nums,vector<int>& dp,int idx) {
         if(idx==nums.size()) return dp[idx]=0;
         
         if(dp[idx]!=0)return dp[idx];
         int ans=0;
         if(nums[idx]-nums[idx-1]==nums[idx-1]-nums[idx-2]){
             ans=1+ap(nums,dp,idx+1);
             sum+=ans;
         }
         else{
         int  newans= ap(nums,dp,idx+1);
         // return dp[idx]=0;
         }
         
        return dp[idx]=ans;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)return 0;
        vector<int>dp(nums.size()+1,0);
        int ans=ap(nums,dp,2);
        return sum;
    }
};