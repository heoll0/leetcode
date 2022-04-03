#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrace(nums, 0, nums.size()-1, ans);
        return ans;
    }
    void backtrace(vector<int> nums, int left, int right, vector<vector<int>> ans){
        if(left == right){
            ans.push_back(nums);
        }
        for(int i = left; i <= right; ++i){
            if(nums[i] == nums[left] && i != left){
                continue;
            }
            swap(nums[i], nums[left]);
            backtrace(nums, i+1, right, ans);
        }
    }
};