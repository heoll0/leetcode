#include<string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        int num_err = 0, loop_num = 0;
        int l_index = 0, r_index = 0;
        while(r > l){
            if(s[l] == s[r]){
                ++l;
                --r;
            }
            else{
                if(loop_num > 0)
                    return false;
                if(s[l+1] == s[r]){
                    ++l;
                    ++num_err;
                    if(num_err == 1){
                        l_index = l-1;
                        r_index = r;
                    }
                    else{
                        l = l_index;
                        r = r_index;
                        num_err = 0;
                        ++loop_num;
                    }
                }
                else if (s[l] == s[r-1])
                {
                    --r;
                    ++num_err;
                    ++loop_num;
                }
                else
                {
                    return false;    
                }           
            }
        }
        return num_err > 1 ? false : true;
    }
};

int main(){
    Solution test;
    test.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");

    return 0;
}