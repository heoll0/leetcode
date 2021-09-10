#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, middle;
        vector<int> result;
        while(high >= low){
            middle = (low + high)/2;
            if(nums[middle] > target) high = middle-1;
            else if (nums[middle] < target) low = middle+1;
            else{
                return vector<int>{lowwer_bound(nums, target, low, middle), higher_bound(nums, target, middle, high)}; 
            }            
        }
        return vector<int>{-1, -1};
    }

    int lowwer_bound(vector<int>& nums, int target, int low, int high){
        int low_index = low, high_index = high;
        while(high_index >= low_index){
            int middle = (low_index + high_index)/2;
            if(nums[middle] < target) low_index = middle+1;
            if(nums[middle] == target) high_index = middle-1;
        }
        return low_index;
    }

    int higher_bound(vector<int>& nums, int target, int low, int high){
        int low_index = low, high_index = high;
        while(high_index >= low_index){
            int middle = (low_index + high_index)/2;
            if(nums[middle] > target) high_index = middle-1;
            if(nums[middle] == target) low_index = middle+1;
        }
        return high_index;
    }
};