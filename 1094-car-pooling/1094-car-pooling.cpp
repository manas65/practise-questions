class Solution {
public:
    static bool comp(vector<int> a, vector<int> b)
        {
        
        if(a[1]<b[1])return true;
        else if(a[1]==b[1])return a[2]<b[2];
        return a[1]<b[1];
        
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