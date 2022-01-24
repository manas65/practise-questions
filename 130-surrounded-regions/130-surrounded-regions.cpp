class Solution {
public:
    void dfs(vector<vector<char>>& board,int row, int col){
        board[row][col]='$';
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        
        for(int i=0;i<4;i++){
            int x=row+dir[i][0];
            int y=col +dir[i][1];
            if(x>=0 && y>=0 && x<board.size() && y<board[0].size() && board[x][y]=='O')
                dfs(board,x,y);
        }
        
        
    }
    
    
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1)
                    if(board[i][j]=='O')
                        dfs(board,i,j);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='$')board[i][j]='O';
                else if(board[i][j]=='O')board[i][j]='X';
            }
        }
    }
};