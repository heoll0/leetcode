#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        vector<vector<string>> ans;
        for(const auto& str : wordList){
            dict.insert(str);
        }
        if(!dict.count(endWord)){
            return ans;
        }
        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_set<string> q1{beginWord}, q2{endWord};
        unordered_map<string, vector<string>> pic;
        bool found = false, reversed = false;
        while(!q1.empty()){
            unordered_set<string> q;
            for(const auto& w : q1){
                string s = w;
                for(size_t i = 0; i < s.size(); ++i){
                    char ch = s[i];
                    for(int j = 0; j < 26; ++j){
                        s[i] = static_cast<char>(j + 'a');
                        if(q2.count(s)){
                            reversed? pic[s].push_back(w) : pic[w].push_back(s);
                            found = true;
                        }
                        if(dict.count(s)){
                            reversed? pic[s].push_back(w) : pic[w].push_back(s);
                            q.insert(s);
                        }
                    }
                    s[i] = ch;
                }
            }
            if(found){
                break;
            }
            for(const auto& w : q){
                dict.erase(w);
            }
            if(q.size() <= q2.size()){
                q1 = q;
            }
            else{
                q1 = q2;
                q2 = q;
                reversed = !reversed;
            }

        }
        vector<string> next{beginWord};
        backtrace(beginWord, endWord, pic, ans, next);
        return ans;
    }

    void backtrace(const string beginWord, const string endWord, unordered_map<string, vector<string>>& pic, vector<vector<string>>& ans, vector<string>& next){
        if(beginWord == endWord){
            ans.push_back(next);
            return;
        }
        for(auto& str : pic[beginWord]){
            next.push_back(str);
            backtrace(str, endWord, pic, ans, next);
            next.pop_back();
        }
    }
};