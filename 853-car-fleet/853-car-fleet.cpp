class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        vector<vector<double>>v;
        int n=s.size();
        for(int i=0;i<n;i++){
            v.push_back({(double)p[i],(double)(target-p[i])/(double)s[i]});
        }
        sort(v.begin(),v.end());
        
        double me=v[n-1][1];
        int ans=1;
        for(int i=n-2;i>=0;i--){
            if(me<v[i][1]){
                ans++;
                me=v[i][1];
            }
        }
        return ans;
    }
};