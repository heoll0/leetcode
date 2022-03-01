class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int result = isConnected.size();
        for(int i = 0; i < isConnected.size(); ++i){
            for(int j = i + 1; j < isConnected.size(); ++j){
                if(isConnected[i][j] == 1 && i != j){
                    isConnected[i][j] = 0;
                    isConnected[j][i] = 0;
                    result -= getConnectedNum(isConnected, j, i);
                }
            }
        }
        return result;
    }

    int getConnectedNum(vector<vector<int>>& isConnected, int j, int i){
        int Num = 1;
        for(int x = j + 1; x < isConnected.size(); ++x){
            if(isConnected[j][x] == 1){
                isConnected[j][x] = 0;
                isConnected[i][x] = 0;
                Num += getConnectedNum(isConnected, x, j);
            }
        }
        return Num;
    }

};