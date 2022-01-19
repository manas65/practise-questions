class Solution {
public:
    
    static bool comp(string&a,string & b){
    if(a+b>b+a)return true;
        return false;
        
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(int num:nums)v.push_back(to_string(num));
        sort(v.begin(),v.end(),comp);
        
        string ans="";
        for(string s:v)ans+=s;
        int i=0;
        while(ans[i]=='0')i++;
        if(i==ans.length())return "0";
        return ans;
    }
};