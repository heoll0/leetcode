#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        int max_count = 0;
        for(const int& num : nums){
            max_count = max(max_count, ++counts[num]);
        }
        vector<vector<int>> buckets(max_count+1);
        for(const auto& p : counts){
            buckets[p.second].push_back(p.first);
        }
        vector<int> result;
        for(int i = max_count; i > 0 && result.size() < k; --i){
            for(const int& num : buckets[i]){
                result.push_back(num);
                if(result.size() == k){
                    break;
                }
            }
        }
        return result;
    }
};