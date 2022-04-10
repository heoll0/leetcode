#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> direction = {1, 0, -1, 0, 1};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        int x = heights.size();
        int y = heights[0].size();
        vector<vector<bool>> can_reach_p(x, vector<bool>(y, false));
        vector<vector<bool>> can_reach_a(x, vector<bool>(y, false));
        for(int i = 0; i < y; ++i){
            dfs(heights, 0, i, can_reach_p);
            dfs(heights, x-1, i, can_reach_a);
        }
        for(int i = 0; i < x; ++i){
            dfs(heights, i, 0, can_reach_p);
            dfs(heights, i, y-1, can_reach_a);
        }
        for(int i = 0; i < x; ++i){
            for(int j = 0; j < y; ++j){
                if(can_reach_a[i][j] && can_reach_p[i][j]){
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<bool>>& can_reach){
        if(can_reach[x][y]){
            return;
        }
        int m, n;
        can_reach[x][y] = true;
        for(int i = 0; i < 4; ++i){
            m = x + direction[i];
            n = y + direction[i+1];
            if(m >= 0 && m < heights.size() && n >=0 && n < heights[0].size() && heights[x][y] <= heights[m][n]){
                    dfs(heights, m, n, can_reach);
            }
        }
    }
};