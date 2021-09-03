#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = 0;
        vector<int> result;
        for(int i = 1; i < numbers.size(); ++i){
            if(numbers[j] + numbers[i] == target){
                result.push_back(j+1);
                result.push_back(i+1);
            }
            if(numbers[j] + numbers[i] > target || i == numbers.size() - 1){
                ++j;
                i = j+1;
            }
        }
        return result;

    }
};

int main(){
    Solution test;
    vector<int> num = {5,25,75};
    test.twoSum(num, 100);

    return 0;
}