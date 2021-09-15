#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(high > low){
            int middle = (high+low)/2;
            if(nums[middle] > nums[high]){
                low = middle + 1;
            }
            else if(nums[middle] < nums[high]){
                high = middle;
            }
            else --high;
        }

        return nums[low];
    }
};

int main(){
    Solution test;
    vector<int> num {3,3,3,3,3,3,3,3,1,3};
    test.findMin(num);

    return 0;

}