class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        int l = 0, r = 0;
        int ans = 1;
        while(l <= r && r < s.size() - 1){
            string sub = s.substr(l, r-l+1);
            if(sub.find(s[r+1]) != s.npos){
                // found
                ++l;
                if(sub.size() == 1){
                    ++r;
                }
            }
            else{
                // not found
                ++r;
                if(ans < sub.size()+1){
                    ans = sub.size()+1;
                }
            }
        }
        return ans;
    }
};