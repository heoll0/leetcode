#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> spaces;
    bool yes = false;
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
                else{
                    spaces.emplace_back(i, j);
                }
            }
        }
        dfs(board, row, col, block, 0);

    }
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& block, int x){
        if(x == spaces.size()){
            yes = true;
            return;
        }
        auto [i, j] = spaces[x];
        for(int q = 0; q < 9 && !yes; ++q){
            if(!row[i][q] && !col[j][q] && !block[i / 3 + (j / 3) * 3][q]){
                board[i][j] = q + 1 + '0';
                row[i][q] = col[j][q] = block[i / 3 + (j / 3) * 3][q] = true;
                dfs(board, row, col, block, x+1);
                row[i][q] = col[j][q] = block[i / 3 + (j / 3) * 3][q] = false;
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