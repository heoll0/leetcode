class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrace(nums, 0, ans);
        return ans;
    }

    void backtrace(vector<int>& nums, int index, vector<vector<int>>& ans){
        if(index == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); ++i){
            swap(nums[i], nums[index]);
            backtrace(nums, index+1, ans);
            swap(nums[i], nums[index]);
        }
    }
};