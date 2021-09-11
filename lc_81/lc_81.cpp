#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int high = nums.size()-1, low = 0, middle;
        if(target > nums[0]){
            while (high >= low){
                middle = (high+low)/2;
                if(nums[middle] > target){
                    low = middle+1;
                }
                else if (nums[middle] < target)
                {
                    high = middle-1;
                }
                else return true;               
            }
            return false;           
        }
        else if (target < nums[0])
        {
            while(high >= low){
                middle = (high+low)/2;
                if(nums[middle] > target){
                    high = middle-1;
                }
                else if (nums[middle] < target)
                {
                    low = middle+1;
                }
                else return true;               
            }
            return false;    
        }           
        else
            return true;
    }
};

int main(){
    Solution test;
    vector<int> num {1,0,1,1,1};
    test.search(num, 0);

    return 0;
}