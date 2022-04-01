#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<TreeNode*> path;
        backtrace(root, ans, path);
        return ans;
    }
    void backtrace(TreeNode* root, vector<string>& ans, vector<TreeNode*>& path){

        path.push_back(root);
        if(root->left){
            backtrace(root->left, ans, path);
            path.pop_back();
        }
        if(root->right){
            backtrace(root->right, ans, path);
            path.pop_back();
        }
        if(!root->left && !root->right){
            string str;
            for(auto& s : path){
                if(s == path.back()){
                    str = str + to_string(s->val); 
                }
                else{
                   str = str + to_string(s->val) + "->"; 
                }
                
            }
            ans.push_back(str);
        }
    }
};