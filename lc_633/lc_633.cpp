#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        long max = floor(sqrt(c)); //long表示范围比int更大的整型数
        long min = 0;
        while(max >= min){
            if(max*max + min*min > c){
                --max;
        }
            else if(max*max + min*min < c){
                ++min;
        }
            else{
                return true;
        }
    }
        return false;
}
};

int main(){
    Solution test;
    test.judgeSquareSum(5);

    return 0;
}