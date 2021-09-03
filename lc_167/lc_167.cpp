#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = numbers.size() - 1;
        int i = 0;
        vector<int> result;
        while(numbers[i] + numbers[j] != target){
            if(numbers[i] + numbers[j] > target)
                --j;
            else
                ++i;
        }
        result.push_back(i+1);
        result.push_back(j+1);
        return result;
    }
};

int main(){
    Solution test;
    vector<int> num = {5,25,75};
    test.twoSum(num, 100);

    return 0;
}