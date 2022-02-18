class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int left=1,right=-1e8;
        unordered_set<int>set;
        for(int num:nums){
            set.insert(num);
            // left=min(left,num);
            right=max(right,num);
            
        }
        // if(left<=0)left=1;
        if(right<=0)return 1;
        
        for(;left<=right;left++){
            if(set.find(left)==set.end())return left;
            
        }
        
        return right+1;
    }
};