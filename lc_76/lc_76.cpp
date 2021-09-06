#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> flag(128, false);
        vector<int> index(128, 0);
        for(int i = 0; i < t.size(); ++i){
            flag[t[i]] = true;
            ++index[t[i]];
        }
        int count = 0, l = 0, min_l = 0, min_size = s.size()+1;
        for(int r = 0; r < s.size(); ++r){
            if(flag[s[r]]){
                if(--index[s[r]] >= 0);
                    ++count;
            }
            while(count == t.size()){
                if(r-l+1 < min_size){
                    min_size = r-l+1;
                    min_l = l;
                }
                if(flag[s[l]] && ++index[s[l]] > 0){
                    --count;
                }
                ++l;
            }       
        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};

int main(){
    Solution test;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    test.minWindow(s,t);

    return 0;

}