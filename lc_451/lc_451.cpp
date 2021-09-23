#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        int max_count;
        for(char a : s){
            max_count = max(max_count, ++count[a]);
        }

        vector<vector<char>> bucket(max_count+1);
        for(auto p : count){
            bucket[p.second].push_back(p.first);
        }

        string result;
        for(int j = max_count; j > 0; --j){
            for(char r : bucket[j]){
                result.insert(result.end(), j, r);
            }
        }
        
        return result;
    }
};