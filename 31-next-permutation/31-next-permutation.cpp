class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        // int i
        // while()
        int i=n-2;
        for(;i>=0;i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        if(i<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int j=n-1;
        for(;j>=0;j--){
            if(nums[j]>nums[i])break;
        }
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
        return;
    }
};