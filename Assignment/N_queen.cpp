class Solution {
public:
    vector<vector<string>> result;
    vector<string> board;
    vector<bool> leftDia;
    vector<bool> rightDia;
    vector<bool> col;
    int sz;
    bool isSafe(int row, int colum){
        bool LD = leftDia[(row - colum)+(sz -1)];
        bool RD = rightDia[row+colum];
        bool column = col[colum];
        if(LD || RD || column) return false;
        return true;
    }
    void solve(int row){
        if(row == sz){
            result.push_back(board);
            return;
        }
        for (int c =0;c<sz;c++){
            if (isSafe(row,c)){
                board[row][c] = 'Q';
                col[c] = true;
                leftDia[(row - c)+(sz -1)] = true;
                rightDia[c+row] = true;
                solve(row+1);
                board[row][c] = '.';
                col[c] = false;
                leftDia[(row - c)+(sz -1)] = false;
                rightDia[c+row] = false;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string> (n, string(n,'.'));
        int dSize = 2*n -1;
        leftDia = vector<bool>(dSize,false);
        rightDia = vector<bool>(dSize,false);
        col = vector<bool>(n,false);
        sz = n;
        solve(0);
        return result;
    }
};