#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> record;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, ans, target, record, 0, 0);
        return ans;
    }

    void dfs(vector<int>& candidates, vector<vector<int>>& ans, int target, vector<int>& record, int sum, int idx){
        if(sum > target){
            return;
        }
        else if(sum == target){
            ans.push_back(record);
            return;
        }

        else{
            for(int i = idx; i < candidates.size(); ++i){
                if(i > idx && candidates[i] == candidates[i-1]){
                    continue;
                }
                record.push_back(candidates[i]);
                sum += candidates[i];
                dfs(candidates, ans, target, record, sum, i+1);
                record.pop_back();
                sum -= candidates[i];
            }
        }
    }
};

int main()
{
    vector<int> candi{3,1,3,5,1,1};
    Solution test;
    test.combinationSum2(candi, 8);
}