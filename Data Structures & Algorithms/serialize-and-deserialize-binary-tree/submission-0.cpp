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

class Codec {
public:
    
    void preorder(TreeNode* root,string &s){
        if(root==nullptr){
            s+="null,";
            return ;
        }
        s+=to_string(root->val)+",";
        preorder(root->left,s);
        preorder(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        preorder(root,s);
        return s;
    }
    TreeNode* build(vector<string> &nodes,int &index){
        if(nodes[index]=="null"){
            index++;
            return nullptr;
        }       
        TreeNode* node=new TreeNode(stoi(nodes[index]));
        index++;
        node->left=build(nodes,index);
        node->right=build(nodes,index);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp="";
        for(char c:data){
            if(c==','){
                nodes.push_back(temp);
                temp="";
            }
            else{
                temp+=c;
            }
        }
        int index=0;
        return build(nodes,index);
    }
};
