#include <vector>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int result = 0;
        for(int i = 0; i < isConnected.size(); ++i){
            if(isConnected[i][i] == 1){
                ++result;
                for(int j = 0; j < isConnected.size(); ++j){
                    if(isConnected[i][j] == 1 && i != j){
                        getConnectedNum(isConnected, j);
                    }
                }
            }
        }
        return result;
    }
    void getConnectedNum(vector<vector<int>>& isConnected, int j){
        isConnected[j][j] = 0;
        for(int x = 0; x < isConnected.size(); ++x){
            if(isConnected[j][x] == 1){
                getConnectedNum(isConnected, x);    
            }
        }
    }

};

int main(){
    Solution test;
    vector<vector<int>> v = {{1,1,0}, {1,1,0}, {0,0,1}};
    test.findCircleNum(v);
}