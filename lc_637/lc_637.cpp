/**
 * Definition for a binary tree node.*/
#include <bits/stdc++.h>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> tree;
        tree.push(root);
        vector<double> ans;
        while(tree.size() > 0){
            double num = 0;
            int size = tree.size();
            for(int i = 0; i < size; ++i){
                if(tree.front()->left){
                    tree.push(tree.front()->left);
                }
                if(tree.front()->right){
                    tree.push(tree.front()->right);
                }
                num += tree.front()->val;
                tree.pop();
            }
            ans.push_back(num / size); 
        }
    return ans;

    }
};

int main(){
    Solution test;
    TreeNode l_node{9};
    TreeNode r_node{20}; 
    TreeNode* l = &l_node;
    TreeNode* r = &r_node;
    TreeNode root_node{3, l, r};
    TreeNode* root = &root_node;
    test.averageOfLevels(root);


}