#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int length = 0, index = 0;
        for(int i = 0; i < dictionary.size(); ++i){
            int s_index = 0, dic_index = 0;
            while(s_index != s.size()){
                if(s[s_index] == dictionary[i][dic_index]){
                    ++dic_index;
                    ++s_index;
            }
                else{
                    ++s_index;
            }
        }
        if(dic_index == dictionary[i].size() && length <= dictionary[i].size()){
            if(length == dictionary[i].size() && dictionary[i] < dictionary[index]){
                index = i;
            }
            if(length < dictionary[i].size()){
                length = dictionary[i].size();
                index = i;
            }
        }
    }
    return length > 0 ? dictionary[index] : "";
    }
};