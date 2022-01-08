class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       // vector<int>lazers;
        int prev=0,next=0, ans=0;
        for(int i=0;i<bank.size();i++){
            int count=0;
            for(int j=0;j<bank[0].size();j++){
                if(bank[i][j]=='1')count++;
            }
            //space optimized
            if(prev==0)prev=count;
            else if(next==0)next=count;
            
            if(prev!=0 && next!=0){
                ans+=(prev*next);
                prev=next;
                next=0;
            }
            
            
        }
    
        return ans;
    }
};
