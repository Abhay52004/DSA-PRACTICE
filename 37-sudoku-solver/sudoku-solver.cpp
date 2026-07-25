class Solution {
public:
    bool ispossible(char val, int row , int col , vector<vector<char>>& board){
        int n = board.size();
        for(int i = 0 ; i<n ; i++){
            if(board[i][col] ==val)
            return false;

        }

        for(int i = 0 ; i<n ; i++){
            if(board[row][i] ==val)
            return false;

        }

        int rowstart = row - row%3;
        int colstart = col - col %3;
        for(int r = rowstart ; r<rowstart+3 ; r++){
            for(int c = colstart ; c<colstart+3;c++){
                if(board[r][c]==val)
                return false;
            }

        }
        return true;
        
    }


    bool  solve(vector<vector<char>>& board){
        int n = board.size();
        for(int row = 0 ; row<n ; row++){
            for(int col = 0 ; col<n ; col ++){
                if(board[row][col] == '.'){
                    for(char var = '1' ; var<='9' ; var++){
                        if(ispossible(var,row,col,board)){
                        board[row][col] = var;
                        bool  kya = solve(board);
                        if(kya)
                        return true;
                        else
                        board[row][col] = '.';

                        }
                    }
                        return false;
                }

            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        // return board;
    }
};