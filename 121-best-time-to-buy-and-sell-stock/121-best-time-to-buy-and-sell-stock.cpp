class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ti0=0,ti1=-1e9;
        for(int i=0;i<prices.size();i++){
            ti0=max(ti0,ti1+prices[i]);
            ti1=max(ti1,-prices[i]);
        }
        return ti0;
    }
};