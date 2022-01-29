class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int si=0,ei=nums.size();
        
        while(si<ei){
            int mid=si+(ei-si)/2;
            // if(nums[mid]==target)return mid;
         if(nums[mid]<target)si=mid+1;
        else ei=mid;
            
        }
        return si;
    }
};