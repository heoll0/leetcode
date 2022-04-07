#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> block(9, vector<bool>(9, false));
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    row[i][board[i][j]-'1'] = true;
                    col[j][board[i][j]-'1'] = true;
                    int index = i / 3 + (j / 3) * 3;
                    block[index][board[i][j]-'1'] = true;
                }
            }
        }
        if(board[0][0] != '.'){
            col[0][board[0][0]-'1'] = false;
            block[0][board[0][0]-'1'] = false;
        }
        dfs(board, row, col, block, 0, 0);

    }
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& block, int x, int y){
        if(col[y][board[x][y]-'1'] || block[x / 3 + (y / 3) * 3][board[x][y]-'1']){
            return;
        }
        if(board[x][y] != '.'){
            col[y][board[x][y]-'1'] = true;
            block[x / 3 + (y / 3) * 3][board[x][y]-'1'] = true; 
        }
        if(x == 8 && y == 8){
            return;
        }
        
        for(int i = x; i < 9; ++i){
            for(int j = y; j < 9; ++j){
                if(board[i][j] == '.'){
                    for(int q = 0; q < 9; ++q){
                        if(!row[i][q]){
                            
                            board[i][j] = q + 1 + '0';
                            row[i][q] = true;
                            dfs(board, row, col, block, i, j);
                            row[i][q] = false;
                            board[i][j] = '.';
                        }
                    }
                }
            }
        }
    }
};

int main(){
    Solution test;
    vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    vector<vector<int>> b{{1,2},{2,2}};
    test.solveSudoku(board);

}