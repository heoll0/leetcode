class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> list(k, 0);
        vector<vector<int>> ans;
        int count = 0;
        backtrace(list, ans, n, k, 1, count);
        return ans;
    }

    void backtrace(vector<int>& list, vector<vector<int>>& ans, int n, int k, int pos, int& count){
        if(count == k){
            ans.push_back(list);
            return;
        }
        for(int i = pos; i <= n; ++i){
            list[count++] = i;
            backtrace(list, ans, n, k, i+1, count);
            --count;
        }
    }
};