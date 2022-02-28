class Solution {
public:
    
    vector<vector<int>> generate(int numRows) {
    vector<int> prev;
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            vector<int>v(i,1);
            for(int j=1;j<i-1;j++){
               v[j]=prev[j-1]+prev[j]; 
            }
            ans.push_back(v);
            prev=v;
        }
        return ans;
    }
};