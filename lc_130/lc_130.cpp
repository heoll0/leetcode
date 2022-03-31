#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    void solve(vector<vector<char>>& board) {
        int len = board.size();
        int wid = board[0].size();
        for(int i = 0; i < wid; ++i){
            if(board[0][i] == 'O'){
                dfs(board, 0, i);
            }
            if(board[len-1][i] == 'O'){
                dfs(board, len-1, i);
            }
        }
        for(int i = 1; i < len - 1; ++i){
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
            if(board[i][wid-1] == 'O'){
                dfs(board, i, wid-1);
            }
        }
        for(int i = 0; i < len; ++i){
            for(int j = 0; j < wid; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'a'){
                    board[i][j] = 'O';
                }
            }
        }

    }
    void dfs(vector<vector<char>>& board, int x, int y){
        if(x < 0 || x > board.size() - 1 || y < 0 || y > board[0].size() - 1){
            return;
        }
        if(board[x][y] != 'O'){
            return;
        }
        board[x][y] = 'a';
        for(int i = 0; i < 4; ++i){
            
            dfs(board, x+direction[i], y+direction[i+1]);
        }
    }
};

int main(){
    vector<vector<char>> board{{'O'}};
    Solution test;
    test.solve(board);
    for(auto& a : board){
        for(auto& b : a){
            cout << b;
        }
    }
}