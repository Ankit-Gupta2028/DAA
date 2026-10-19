class Solution {
int number_of_neg(vector<vector<int>>& board,int row,int col,int n,int m){
    int total = 0;

    for(int i=-1;i<=1;i++){
        for(int j= -1;j<=1;j++){
            int newrow = row+i;
            int newcol = col+j;
            if(newrow >=0 && newrow < n && newcol >=0 && newcol < m){

                if(i==0 && j == 0){
                    continue;
                }
                if(board[newrow ][newcol] == 1 || board[newrow][newcol] == 3){
                    total +=1;
                }
            }
        }
    }
    if(total == 3 && board[row][col] == 0){
        return 1;
    }
    if(total > 3 && board[row][col] == 1){
        return 0;
    }
    if(total < 2 && board[row][col] == 1){
        return 0;
    }
    if((total == 2 || total ==3) && board[row][col] == 1 ){
        return 1;
    }
    return 0;
}
public:
    void gameOfLife(vector<vector<int>>& board) {
        

        // let when 0 convert into 1 make it 2;
        // let when 1 convert into 0 make it 3;
        int n = board.size();
        int m  = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curr_val = number_of_neg(board,i,j,n,m);

                if(curr_val != board[i][j]){
                    if(board[i][j] == 0){
                        board[i][j] = 2;
                    }else{
                        board[i][j] = 3;
                    }
                }

                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(board[i][j] == 2){
                    board[i][j] = 1;
                }
                if(board[i][j] == 3){
                    board[i][j] = 0;
                }  
                
            }
        }
        
    }
};