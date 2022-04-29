#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // dp O(n^2)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    // binary O(nlogn)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i = 1; i < n; ++i){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                auto iter = lower_bound(ans.begin(), ans.end(), nums[i]);
                *iter = nums[i];
            }
        }
        return ans.size();
    }
};