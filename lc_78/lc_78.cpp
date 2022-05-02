class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> num;
        vector<vector<int>> ans;
        backtrace(num, ans, nums, 0);
        return ans;
    }
    void backtrace(vector<int>& num, vector<vector<int>>& ans, const vector<int>& nums, int index){
        ans.push_back(num);
        if(index == nums.size()){
            return;
        }
        for(int i = index; i < nums.size(); ++i){
            num.push_back(nums[i]);
            backtrace(num, ans, nums, i + 1);
            num.pop_back();
        }
    }
};