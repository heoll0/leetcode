class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int result = 0;
        for(int i = 0; i < isConnected.size(); ++i){
            if(isConnected[i][i] == 1){
                ++result;
                for(int j = 0; j < isConnected.size(); ++j){
                    if(isConnected[i][j] == 1 && i != j){
                        isConnected[i][i] = 0;
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
                if(isConnected[x][x] != 0){
                    getConnectedNum(isConnected, x); 
                }
            }
        }
    }

};