class Solution {
private:
    bool isValidMove(vector<vector<char>>& board, int i, int j, char d){
        for(int k=0 ; k<9 ; ++k){
            if(board[i][k]==d || board[k][j]==d) 
                return 0;
        }

        for (int row = (i/3)*3; row<(i/3)*3+3 ; row++) {
            for (int col = (j/3)*3; col<(j/3)*3+3 ; col++) {
                if (board[row][col] == d) 
                    return 0;
           }
        }

        return 1;
    }
    bool solve(vector<vector<char>>& board, int i, int j){
        
        if(i==9)  return 1;

        if(board[i][j] != '.') 
            return solve(board, i+(j+1)/9, (j+1)%9);

        for (char d='1' ; d<='9' ; ++d){
            if( isValidMove(board, i, j, d) ){
                board[i][j] = d;
                if( solve(board, i+(j+1)/9, (j+1)%9) )  
                    return 1;
            }
        }

        board[i][j] = '.';
        return 0;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};