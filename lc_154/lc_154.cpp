#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int middle;
        if(nums.size() == 1)
            return nums[0];
        else{
            while(nums[low] == nums[high] && high > low){
                ++low;
                }
            while(high > low && nums[low] == nums[low+1]){
                ++low;
            } 
        }
        
        int l = nums[low];
        while(high >= low){
            middle = (high + low)/2;
            if(nums[middle] >= l){
                low = middle+1;
            }
            else if(nums[middle] <= nums.back()){
                high = middle-1;
            }
        }
        if(low > nums.size()-1) low = nums.size()-1;
        return nums[low] < l ? nums[low] : l; 
    }
};

int main(){
    Solution test;
    vector<int> num {3,1,3};
    cout << test.findMin(num) << endl;

    return 0;
}