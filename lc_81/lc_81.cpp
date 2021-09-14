#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int high = nums.size()-1, low = 0, middle;
        while(nums[low] == nums[high] && high > low){
            ++low;
        }
        int l = nums[low], r = nums[high];
        if(target == r || target == l) return true;
        while(high >= low){
            middle = (high+low)/2;
            if(nums[middle] == target) return true;
            if(nums[middle] <= r){               
                if(target < r && target > nums[middle])
                    low = middle+1;
                else
                    high = middle-1; 
            }
            else if(nums[middle] >= l){
                if(target > l && target < nums[middle])
                    high = middle-1;
                else
                    low = middle+1;
            }
        }
        return false;
    }
};

int main(){
    Solution test;
    vector<int> num {1,1};
    test.search(num, 0);

    return 0;
}