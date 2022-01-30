class Solution {
public:
    int findMin(vector<int>& nums) {
         int si=0,ei=nums.size()-1 ;
        int minans=1e8;
        while(si<=ei){
            int mid=si+(ei-si)/2;
             minans=min(minans,nums[si]);
            if(nums[si]<nums[mid]){
                minans=min(minans,nums[si]);
                si=mid+1;
            }
            else if(nums[ei]>nums[mid]){
                minans=min(minans,nums[mid]);
                ei=mid-1;
            }
            else  si++;
        }
        return minans;
    }
};