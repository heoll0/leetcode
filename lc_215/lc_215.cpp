#include<vector>
using namespace std;

class Solution {
public:

    int quick_sort(vector<int>& nums, int l, int r){

        int first = l, last = r, k = nums[first];
        while(first < last){
            while(first < last && nums[last] >= k){
                --last;
            }
            nums[first] = nums[last];
            while(first < last && nums[first] <= k){
                ++first;
            }
            nums[last] = nums[first];
        }
        nums[first] = k;

        return first;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        int l = 0, r = nums.size() - 1;
        while(l < r){
           int m = quick_sort(nums, l, r); 
           if(m == target){
               return nums[m];
           }
           else if(m > target){
               r = m - 1;
           }
           else{
               l = m + 1;
           }
        }
        return nums[l];   
    }
};

int main(){
    vector<int> nums = {7,6,5,4,3,2,1};
    Solution test;
    test.findKthLargest(nums, 2);

    return 0;
}