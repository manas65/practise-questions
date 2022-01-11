class Solution {
public:
    int reverse(int x) {
       if(x>INT_MAX || x<INT_MIN)return 0;
        int ans=0;
        bool isNeg=false;
        if(x<0)isNeg=true;
        x=abs(x);
        
        while(x>0){
            // if(x/10>INT_MAX)
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && x%10>7) ){
                return 0;
            }
            ans=ans*10+x%10;
            x/=10;
        }
        if(isNeg)ans=-ans;
        return ans;
    }
};