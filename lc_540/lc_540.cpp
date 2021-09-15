#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int middle;
        while(high > low){
            middle = (high+low)/2;
            if(middle % 2 != 0){
                if(nums[middle] == nums[middle+1]){
                    high = middle-1;
                }
                else if(nums[middle] == nums[middle-1]){
                    low = middle+1;
                }
                else return nums[middle];
            }
            else{
                if(nums[middle] == nums[middle+1]){
                    low = middle+2;
                }
                else if(nums[middle] == nums[middle-1]){
                    high = middle-2;
                }
                else return nums[middle];
            }
        }
        return nums[low];
    }
};

int main(){
    Solution test;
    vector<int> num {1,1,2,3,3,4,4,8,8};

    test.singleNonDuplicate(num);

    return 0;
}