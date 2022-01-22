class Solution {
public:
    
    bool sum_(vector<int>& nums,int idx,int sum,vector<vector<int>>&dp){
        if(idx==nums.size()){
            if(sum==0)return 1;
            return 0;
        }
        if(sum==0)return 1;
        
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        
        bool res=false;
        
        for(int i=idx;i<nums.size();i++){
           if(sum-nums[i]>=0)
            res=res || sum_(nums,i+1,sum-nums[i],dp);
            if(res)return 1;
        }
        
        return dp[idx][sum]=res;
    }
    
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(int ele:nums)sum+=ele;
        
        if(sum%2==0){
            sum/=2;
            vector<vector<int>>v(nums.size(),vector<int>(sum+1,-1));
            return sum_(nums,0,sum,v);
        }
        return false;
    }
};