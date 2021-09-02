#include<vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> list;
        list.reserve(27);
        for(int i =0; i < s.size(); ++i){
            list[s[i] - 'a'] = i;
        }
        int last = list[s[0] - 'a'];
        int first = 0;
        vector<int> result;
        for(int j =1; j < s.size(); ++j){            
            if(list[s[j] - 'a'] > last)
                last = list[s[j] - 'a'];
            if(j == last){
                if(j == s.size() - 1){
                    result.push_back(j - first + 1);
                }
                else{
                    result.push_back(last - first + 1);
                    last = list[s[j+1] - 'a'];
                    first = j+1;
                }
            }
        }
        return result;

    }
};

int main(){
    Solution test;
    test.partitionLabels("ababcbacadefegdehijhklij");

    return 0;
}