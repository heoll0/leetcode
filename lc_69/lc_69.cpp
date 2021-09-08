class Solution {
public:
    int mySqrt(int x) {
        int min = 1, max = x;
        int num = 0;
        if(x == 0){
            return 0;
        }
        while(max >= min){
            num = (min + max)/2;
            if(x/num > num)
                min = num + 1;
            else if (x/num < num)
            {
                max = num - 1;
            }
            else
                return num;                
    }
    return max;
    }
};

int main(){
    Solution test;
    test.mySqrt(1);

    return 0;
}