#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> direction{-1,0,1,0,-1};

    int shortestBridge(vector<vector<int>>& grid) {
        int ans = 0;
        bool breakLoop = true;
        queue<pair<int, int>> island;
        for(int i = 0; i < grid.size() && breakLoop; ++i){
            for(int j = 0; j < grid[0].size() && breakLoop; ++j){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, island);
                    breakLoop = false;
                }
            }
        }
        while(!island.empty()){
            ++ans;
            int size = island.size();
            for(int i = 0; i < size; ++i){
                int x = island.front().first;
                int y = island.front().second;
                island.pop();
                for(int j = 0; j < 4; ++j){
                    if(x+direction[j] < 0 || x+direction[j] >= grid.size() || y+direction[j+1] < 0 || y+direction[j+1] >= grid[0].size()){
                        continue;
                    }
                    if(grid[x+direction[j]][y+direction[j+1]] == 0){
                        grid[x+direction[j]][y+direction[j+1]] = 2;
                        island.push({x+direction[j], y+direction[j+1]});
                    }
                    else if(grid[x+direction[j]][y+direction[j+1]] == 1){
                        return ans-1;
                    }
                }
            }
        }
        return 0;

    }

    void dfs(vector<vector<int>>& grid, int x, int y, queue<pair<int, int>>&   island){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()){
            return;
        }
        if(grid[x][y] != 1){
            return;
        }
        grid[x][y] = 2;
        island.push({x, y});
        for(int i = 0; i < 4; ++i){
            dfs(grid, x + direction[i] , y + direction[i+1], island);
        }
    }
};

int main(){
    Solution test;
    vector<vector<int>> grid{{0, 0, 1, 0, 1}, {0, 1, 1, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    test.shortestBridge(grid);
}