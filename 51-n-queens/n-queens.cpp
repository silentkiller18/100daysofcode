class Solution {
public:
    bool isSafe(int i, int j, int n, vector<string> &board){
        int row=i, col=j;
        while(i>=0 and j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        i=row;
        j=col;

        while(j>=0){
            if(board[i][j]=='Q') return false;
        j--;
        }

        i=row;
        j=col;
        while(i<n and j>=0){
            if(board[i][j]=='Q') return false;
        i++;
        j--;
        }
    return true;
    }

    void helper(int j, int n, vector<string> &board, vector<vector<string>> &result){
        if(j==n){
            result.push_back(board);
        return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,j,n,board)){
                board[i][j]='Q';
                helper(j+1,n,board,result);
                board[i][j]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        helper(0,n,board,result);

    return result;
    }
};