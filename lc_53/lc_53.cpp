class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int x = 0;
        for(auto& num : nums){
            x += num;
            if(x > max){
                max = x;
            }
            if(x < 0){
                x = 0;
            }
        }
        return max;
    }
};