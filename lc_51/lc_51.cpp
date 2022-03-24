#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> column(n, false);
        vector<bool> ldiag(2*n-1, false);
        vector<bool> rdiag(2*n-1, false);
        backtrace(ans, board, column, ldiag, rdiag, n, 0);
        return ans;
    }

    void backtrace(vector<vector<string>>& ans, vector<string>& board, vector<bool>& column, vector<bool>& ldiag, vector<bool>& rdiag, int n, int row){
        if(row == n){
            ans.push_back(board);
        }
        for(int i = 0; i < n; ++i){
            if(column[i] || ldiag[row+i] || rdiag[row-i+n-1]){
                continue;
            }
            board[row][i] = 'Q';
            column[i] = ldiag[row+i] = rdiag[row-i+n-1] = true;
            backtrace(ans, board, column, ldiag, rdiag, n, row+1);
            column[i] = ldiag[row+i] = rdiag[row-i+n-1] = false;
            board[row][i] = '.';
        }
    }
};