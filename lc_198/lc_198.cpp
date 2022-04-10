// space complexity O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        for(int i = 2; i <= n; ++i){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[n];
    }
};

// space complexity O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int pre2 = 0, pre1 = nums[0], cur;
        for(int i = 2; i <= n; ++i){
            cur = max(pre2 + nums[i-1], pre1);
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};