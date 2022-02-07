class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=1e8, count=0;
        int k=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(prev!=nums[i]){
                prev=nums[i];
                count=1;
            }
            else if(prev==nums[i] && count==1)count++;
            else {
                nums[i]=1e8;
                k++;
            }
            
        }
         int idx=-1;
        for(int i=0;i<n;i++){
            if(idx==-1 && nums[i]==1e8)
            {
                idx=i;
                break;
            }
           
        }
        if(idx!=-1){
        for(int i=idx+1;i<n;i++){
            if(nums[i]!=1e8){
                swap(nums[i],nums[idx]);
                idx++;
            }
        }
        }
        
        return n-k;
    }
};