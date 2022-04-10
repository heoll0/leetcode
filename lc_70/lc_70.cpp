class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1){
            return n;
        }
        else{
            int pre1 = 2, pre2 = 1, cur;
            for(int i = 3; i <= n; ++i){
                cur = pre1 + pre2;
                pre2 = pre1;
                pre1 = cur;
            }
            return cur;
        }
    }
};