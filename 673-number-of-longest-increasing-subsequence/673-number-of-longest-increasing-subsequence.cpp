class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
     vector<int>lis(nums.size(),1);
        vector<int>count(nums.size(),1);
        int maxlen=1;
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                
                if(nums[j]<nums[i]){
                    if(lis[j]+1>lis[i])lis[i]=lis[j]+1,count[i]=count[j];
                
                else if(lis[j]+1==lis[i])//same len ki exist krti hai
                    count[i]+=count[j];
            }
            }
            maxlen=max(maxlen,lis[i]);
        }
        
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(lis[i]==maxlen)ans+=count[i];
        }
        return ans;
    }
};