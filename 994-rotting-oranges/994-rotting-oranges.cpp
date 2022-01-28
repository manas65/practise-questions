class Solution {
public:
    class index{
        public:
        int x;
        int y;
        index(int x,int y){
            this->x=x;
            this->y=y;
        }
    };
    
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int t=0;
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        //count rotten and fresh and put rotten in bfs queue
        queue<index>q;
        int freshOrange=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)freshOrange++;
            }
        }
        
        
        //if rotten =0  return 0
        if(freshOrange==0)return 0;
        
        
        //bfs
        while(q.size()!=0){
            int size=q.size();
            while(size--){
                index front=q.front();
                q.pop();
                    
                for(int i=0;i<dir.size();i++){
                    int row=front.x+dir[i][0];
                    int col=front.y+dir[i][1];
                    if(row>=0  && col>=0 && row<n && col<m &&  grid[row][col]==1 ){
                        freshOrange--;
                        grid[row][col]=2;
                           if(freshOrange==0)return t+1;
                q.push({row,col});                    
                        
                    }
                }
                
            }
            t++;
        }
        
        return -1;
    }
};