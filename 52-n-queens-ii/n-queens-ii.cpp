class Solution {
public:
  bool ispossible(int row , int col , int n , int board[10][10]){
        int durow = row;
        int ducol = col ; 
        while(col>=0){
            if(board[row][col] == 1)
            return false;
            col--;
        }

        row = durow;
        col = ducol;
        while(row<n && col>=0){
             if(board[row][col] == 1)
            return false;
            col--;
            row++;
        }

        
        row = durow;
        col = ducol;
        while(row>=0 && col >= 0){
              if(board[row][col] == 1)
            return false;
            col--;
            row--;
        }
        return true;
    }

 int   solve(int col , int n , int board[10][10] , int &out){
        if(col  == n){
             out++;
        }
        for(int row = 0 ; row<n ; row ++ ){
            if(ispossible(row,col, n , board)){
                board[row][col ] = 1 ;
                // out++;/
                solve(col + 1 , n ,board , out);
                 board[row][col ] = 0 ;
            }
        }
        return out;
    }
    int totalNQueens(int n) {
        int out = 0 ;
        int board[10][10];
        solve(0,n,board,out);
        return out;
    }
};