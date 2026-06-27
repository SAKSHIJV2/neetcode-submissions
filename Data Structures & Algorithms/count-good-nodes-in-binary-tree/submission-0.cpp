/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int dfs(TreeNode* root,int maxFar){
        int count=0;
        if(root==nullptr){
            return 0;
        }
        if(root->val>=maxFar){
            count=1;
        }
        maxFar=max(maxFar,root->val);
        count+=dfs(root->left,maxFar);
        count+=dfs(root->right,maxFar);
        return count;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};
