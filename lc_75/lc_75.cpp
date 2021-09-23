#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int index_0 = 0, index_2 = nums.size() - 1;
        for(int i = 0; i <= index_2; ++i){
            if(nums[i] == 0){
                nums[i] = nums[index_0];
                nums[index_0++] = 0;
                i = max(index_0 - 1,--i);                
            }
            else if(nums[i] == 2){
                nums[i] = nums[index_2];
                nums[index_2--] = 2;   
                --i;
            }
        }
    }
};

int main(){
    Solution test;
    vector<int> num {2,0,2,1,1,0};
    test.sortColors(num);
}