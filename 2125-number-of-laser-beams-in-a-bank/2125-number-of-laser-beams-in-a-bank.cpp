class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>lazers;
        for(int i=0;i<bank.size();i++){
            int count=0;
            for(int j=0;j<bank[0].size();j++){
                if(bank[i][j]=='1')count++;
            }
            lazers.push_back(count);
        }
    
        int prev=0,next=0, ans=0;
        for(int i=0;i<lazers.size();i++){
            if(lazers[i]==0)continue;
            else if(prev==0)prev=lazers[i];
            else if(next==0)next=lazers[i];
            
            if(prev!=0 && next!=0){
                ans+=(prev*next);
                prev=next;
                next=0;
            }
        }
        return ans;
    }
};
//3 0 2 1


//0 3 0

//  0 1 0 2 4 0 8 9 9