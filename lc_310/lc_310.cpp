#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    int longest_node = 0;
    vector<int> long_path;
    bool flag = true;
    int depth = 0;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return {0};
        }
        visited.resize(n, false);
        graph.resize(n);
        for(const auto& a : edges){
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        int node = edges[0][0];
        dfs(node, 0);
        int start_node = longest_node;
        depth = 0;
        dfs(start_node, 0);
        int end_node = longest_node;
        vector<int> path;
        find_path(start_node, end_node, path);
        if(long_path.size() % 2 == 0){
            return {long_path[long_path.size()/2], long_path[long_path.size()/2 - 1]};
        }
        else{
            return {long_path[long_path.size()/2]};
        }
    }
    void find_path(int start, int end, vector<int>& path){
        if(visited[start] || !flag){
            return;
        }
        visited[start] = true;
        path.push_back(start);
        if(start == end){
            long_path = path;
            flag = false;
            return;
        }
        for(auto node : graph[start]){
            find_path(node, end, path);
        }
        path.pop_back();
        visited[start] = false;
    }
    void dfs(int node, int len){
        if(visited[node]){
            return;
        }
        if(len > depth){
            depth = len;
            longest_node = node;
        }
        visited[node] = true;
        for(const auto& x : graph[node]){
            dfs(x, len + 1);
        }
        visited[node] = false;
    }
};

int main(){
    vector<vector<int>> edge{{1,0},{1,2},{1,3}};
    Solution test;
    auto ans = test.findMinHeightTrees(4, edge);
    for(auto node : ans){
        cout << node << ' ';
    }
}