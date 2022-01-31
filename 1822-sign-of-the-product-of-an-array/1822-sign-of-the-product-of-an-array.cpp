class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count=0;
        for(int ele:nums){
            if(ele<0)count++;
            else if(ele==0)return 0;
        }
        if(count%2==0)return 1;
        return -1;
    }
};