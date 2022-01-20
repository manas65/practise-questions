class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l=1;
        int r=1;
        int i=0,j=nums.size()-1;
        int ans=-1e8;
        while(i<nums.size() && j>=0){
            l*=nums[i++];
            r*=nums[j--];
            ans=max({ans,l,r});
            
            if(l==0)l=1;
            if(r==0)r=1;
        }
        return ans;
    }
};