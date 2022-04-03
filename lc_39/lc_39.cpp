#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> record;
        dfs(candidates, ans, target, record, 0);
        return ans;
    }

    void dfs(vector<int>& candidates, vector<vector<int>>& ans, int target, vector<int>& record, int sum){
        if(sum > target){
            return;
        }
        else if(sum == target){
            ans.push_back(record);
            return;
        }
        else{
            for(int i = 0; i < candidates.size(); ++i){
                record.push_back(candidates[i]);
                sum += candidates[i];
                dfs(candidates, ans, target, record, sum);
                record.pop_back();
                sum -= candidates[i];
            }
        }
    }
};