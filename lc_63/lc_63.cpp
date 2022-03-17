class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int num = 0;
    vector<int> record(obstacleGrid[0].size(), 0);
    record[0] = (obstacleGrid[0][0] == 0);
    for(int i = 0; i < obstacleGrid.size(); ++i){
        for(int j = 0; j < obstacleGrid[0].size(); ++j){
            if(obstacleGrid[i][j] == 1){
                record[j] = 0;
                continue;
            }
            else if(j >= 1){
                record[j] += record[j-1];
            }
        }
    }
    return record.back();
}
        
};