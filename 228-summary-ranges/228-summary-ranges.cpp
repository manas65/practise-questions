class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();
  

        int i=0;
        while(i<n){
            int start=nums[i];
            int end=nums[i];
            while(i+1<n && (nums[i+1]==nums[i]+1 || nums[i+1]==nums[i])){
                end=nums[i+1];
                i++;
            }
            if(start!=end){
                string ans_=to_string(start)+"->" + to_string(end);
            ans.push_back(ans_);
                
            }
            else {
                string ans_=to_string(start);
                ans.push_back(ans_);
              
            }
            i++;
        }
        
        return ans;
    }
};