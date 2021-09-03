#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        string t_t = t;
        vector<int> list;
        int first = 0;
        int last = s.size() + 1;
        int j = 0;
        for(int i = 0; i < s.size(); ++i){
            if(t.find(s[i]) != string::npos){
                list.push_back(i);
                t.erase(t.begin() + t.find(s[i]));
            }
            if(t.empty()){
                if(list[list.size()-1] - list[j] < last - first){
                    first = list[0];
                    last = list[list.size()-1];
                    }
                if(s.find(s[list[j]], list[j]+1) == string::npos || s.find(s[list[j]], list[j]+1) > list[list.size()-1]){
                    t.push_back(s[list[j]]);
                    ++j;
                }
                else
                    ++j;
            }
        }
        result.assign(s.begin()+first, s.begin()+last);
        return result;
    }
};

int main(){
    Solution test;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    test.minWindow(s,t);

    return 0;

}