class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> num;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        backtrace(num, ans, nums, 0);
        return ans;
    }
    void backtrace(vector<int>& num, vector<vector<int>>& ans, const vector<int>& nums, int index){
        ans.push_back(num);
        if(index == nums.size()){
            return;
        }
        for(int i = index; i < nums.size(); ++i){
            if(i > index && nums[i] == nums[i-1]){
                continue;               
            }
            num.push_back(nums[i]);
            backtrace(num, ans, nums, i + 1);
            num.pop_back();  
        }
    }
};