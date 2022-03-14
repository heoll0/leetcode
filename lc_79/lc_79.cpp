#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    bool exist(vector<vector<char>>& board, string word) {
        int width = board.size();
        int length = board[0].size();
        bool find = false;
        vector<vector<bool>> visited(width, vector<bool>(length, false));
        for(int i = 0; i < width; ++i){
            for(int j = 0; j <length; ++j){
                dfs(board, word, visited, find, i, j, 0);
            }
        }
        return find;
    }

    void dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, bool& find, int i, int j, int pos){
        if( j < 0 || j > board[0].size() - 1|| i < 0 || i > board.size() - 1 ){
            return;
        }
        if(word[pos] != board[i][j] || visited[i][j] || find){
            return;
        }
        if(pos == word.size()-1){
            find = true;
            return;
        }
        visited[i][j] = true;
        for(int m = 0; m < 4; ++m){
            dfs(board, word, visited, find, i+direction[m], j+direction[m+1], pos+1);
        }
        visited[i][j] = false;
    }
};

int main(){
    Solution test;
    vector<vector<char>> board{{"a", "b"},{"c", "d"}};
    string word = "abd";
    test.exist(board,word);
}