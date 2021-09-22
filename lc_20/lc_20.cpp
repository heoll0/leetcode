#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> stk;
        for(char c : s){
            if(pairs.count(c)){
                stk.push(c);
            }
            else if(!stk.empty() && pairs[stk.top()] == c){
                stk.pop();
            }
            else{
                return false;
            }
        }
        return stk.empty();
    }
};