#include<vector>
using namespace std;

class Solution {
public:

    int getKthNum(vector<int>& num1, vector<int>& num2, int K){
        int len_1 = num1.size(), len_2 = num2.size();
        int index_1 = 0, index_2 = 0;
         while(1){
            
            if(index_1 == len_1){
                return num2[index_2 + K - 1];
            }
            if(index_2 == len_2){
                return num1[index_1 + K - 1];
            }
            if(K == 1){
                return min(num2[index_2], num1[index_1]);
            }
            int cnt = K/2 - 1;
            int newindex_1 = min(cnt+index_1, len_1-1);
            int newindex_2 = min(cnt+index_2, len_2-1);
            if(num1[newindex_1] <= num2[newindex_2]){
                K = K-(newindex_1-index_1)-1;
                index_1 = newindex_1 + 1;
                
            }
            else{
                K = K-(newindex_2-index_2)-1;
                index_2 = newindex_2 + 1;                
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l_1 = nums1.size(), l_2 = nums2.size();
        if((l_1+l_2) % 2 == 0)
            return (getKthNum(nums1, nums2, (l_2+l_1)/2) + getKthNum(nums1, nums2, (l_2+l_1)/2 + 1))/2.0;
        else
            return getKthNum(nums1, nums2, (l_2+l_1+1)/2);
    }
};

int main(){
    Solution test;
    vector<int> num1 {1,2};
    vector<int> num2 {3,4};
    test.findMedianSortedArrays(num1, num2);
    return 0;
}