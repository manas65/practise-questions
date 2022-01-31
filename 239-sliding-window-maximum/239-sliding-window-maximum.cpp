class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<vector<int>>pq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            while(pq.size()!=0 && pq.top()[1]<=(i-k))pq.pop();//suppos i at 8 k=3 so inc idx  6 7 8 so remove remove before 6
            
            pq.push({nums[i],i});
            if(i>=k-1)ans.push_back(pq.top()[0]);
            
        }
        return ans;
    }
};