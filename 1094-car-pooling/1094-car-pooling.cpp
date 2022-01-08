class Solution {
public:
    static bool comp(vector<int> lhs, vector<int> rhs)
    {
        if(lhs[1]<rhs[1] || (lhs[1]==rhs[1] && lhs[2]<rhs[2]))
            return true ;
        return false ;
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),comp);
        int curr=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
       for(int i=0;i<trips.size();i++){
          while(!pq.empty() && pq.top().first<=trips[i][1]){
               curr-=pq.top().second;
               pq.pop();
           }
           curr+=trips[i][0];
           pq.push({trips[i][2],trips[i][0]});
           if(curr>capacity)return false;
       } 
        
        return true;
        
        
        
    }
};