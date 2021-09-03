#include<vector>
using namespace std;


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int num = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] > nums[i+1]){
                ++num;
                if(i != 0 && i != nums.size() - 2 && nums[i] > nums[i+2] && nums[i-1] > nums[i+1])
                    ++num;
            }
            if(num > 1)
                return false;            
        }
        return true;
    }
};

int main(){
    Solution test;
    vector<int> nums = {5,7,1,8};
    test.checkPossibility(nums);

    return 0;
}