class Solution {
public:
    vector<int>v,backup;
    int n=0;
    Solution(vector<int>& nums) {
        n=nums.size();
        v=nums;
        backup=nums;
    }
    
    vector<int> reset() {
        v=backup;
        return v;
    }
    
    vector<int> shuffle() {
  unordered_map<int,int>map;
        
        
        vector<int>ans(n,0);
        int count=0;
        // int i=0;
        while(count<n){
            int idx=rand()%n;
            while(map.find(idx)!=map.end())//idx is not presnt in map
                idx=rand()%n;
                           
               map[idx]++;
                
                ans[count++]=v[idx];
 
            
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */