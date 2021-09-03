#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int index_1 = 0;
        int index_2 = 0;
        while(1){            
            if(index_2 == n){
                result.insert(result.end(), nums1.begin()+index_1, nums2.begin()+m);
                break;
            }
            if(index_1 == m){
                result.insert(result.end(), nums2.begin()+index_2, nums2.end());
                break;
            }
            if(nums1[index_1] < nums2[index_2]){
                result.push_back(nums1[index_1]);
                ++index_1;
        }
            else{
                result.push_back(nums2[index_2]);
                ++index_2;
            }
        }
        nums1.assign(result.begin(), result.end());
    }
};

int main(){
    Solution test;
    vector<int> num1 = {1};
    vector<int> num2 = {};
    test.merge(num1,1,num2,0);

    return 0;
}