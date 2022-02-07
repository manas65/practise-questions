class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int count=1e8;
        int k=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==count)nums[i]=1e8,k++;
            else{
                count=nums[i];
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
        // arr.resize()
        
        return n-k;
        
    }
};