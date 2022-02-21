class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
     int i=0,idx=0;
        
        int n=nums.size();
        // if(n==0)return 0;
        int k=0;
        while(i<n){
            if(nums[i]==val){
                i++;
                k++;
            }
            else {
                nums[idx]=nums[i];
                i++;
                
                idx++;
            }
        }
        // if(idx>=0 && idx<n && nums[idx]==val)k++;
        return idx;
    }
};