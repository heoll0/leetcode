#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        
        while(1){
            int middle = (low + high)/2;
            if(nums[middle] > target) high = middle-1;
            else if (nums[middle] < target) low = middle+1;
            else break;            
        }
    }

    int lowwer_bound(vector<int>& nums, int target, int low, int high){
        int low_index = low, high_index = high;
        while(1){
            int middle = (low_index + high_index)/2;
            if(nums[middle] < target) low_index = middle+1;
            if(nums[middle] == target) high_index = middle-1;
        }
    }
};