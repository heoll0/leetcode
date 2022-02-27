#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()){
            return 0;
        }
        int area = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    area = max(area, Getarea(grid, i, j));
                }
            }
        }
        return area;
    }
    int Getarea(vector<vector<int>>& grid, int x, int y){
        if(grid[x][y] == 0){
            return 0;
        }
        int area = 1;
        grid[x][y] = 0;
        if(x + 1 < grid.size()){
            area += Getarea(grid, x+1, y);
        }
        if(x - 1 >= 0){
            area += Getarea(grid, x-1, y);
        }
        if(y + 1 < grid[0].size()){
            area += Getarea(grid, x, y+1);
        }
        if(y - 1 >= 0){
            area += Getarea(grid, x, y-1);
        }
        return area;
    }    
};

int main(){
    Solution test;
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << test.maxAreaOfIsland(grid) << endl;
}