#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int i = 0, j = 0;
        double result;
        while(1){
            if(i == nums1.size()){
                nums.insert(nums.end(), nums2.begin()+j, nums2.end());
                break;
            }
            if(j == nums2.size()){
                nums.insert(nums.end(), nums1.begin()+i, nums1.end());
                break;
            }
            if(nums1[i] <= nums2[j]){
                nums.push_back(nums1[i]);
                ++i;
            }
            else{
                nums.push_back(nums2[j]);
                ++j;
            }
        }
        int length = nums.size();
        if(length % 2 == 0){
            result = (double(nums[length/2]) + double(nums[(length/2)-1]))/2;
        }
        else
            result = double(nums[(length-1)/2]);
        
        return result;
    }
};

int main(){
    Solution test;
    vector<int> num1 {1,2};
    vector<int> num2 {3,4};
    test.findMedianSortedArrays(num1, num2);
    return 0;
}