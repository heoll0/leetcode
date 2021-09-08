#include<string>
using namespace std;

class Solution {
public:

    bool check(string s, int l, int r){
        while(r > l){
            if(s[l] == s[r]){
                ++l;
                --r;
            }
            else
                return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (r > l)
        {
            if(s[r] == s[l]){
                ++l;
                --r;
            }
            else{
                return check(s, l+1, r) || check(s, l, r-1);
            }
        }
        return true;
    }
};

int main(){
    Solution test;
    test.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");

    return 0;
}