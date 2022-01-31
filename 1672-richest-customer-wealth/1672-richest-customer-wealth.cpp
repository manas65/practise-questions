class Solution {
public:
    int maximumWealth(vector<vector<int>>& nums) {
        int maxsum=0;
        
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=0;j<nums[0].size();j++){
                sum+=nums[i][j];
            }
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};