class Solution {
public:
    vector<int> ngor(vector<int>& nums){
        stack<int>st;
        
        int n=nums.size();
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            while(st.size()!=0 && nums[st.top()]<nums[i]){
                v[st.top()]=i;
                st.pop();
                
            }
            st.push(i);
        }
        
        return v;
        
        
    }
    
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>next=ngor(temperatures);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(next[i]!=0){
                ans.push_back(next[i]-i);
            }
            else ans.push_back(0);
        }
        return ans;
    }
};