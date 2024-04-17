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
    private:
    string sm="~";
    string alphabet="abcdefghijklmnopqrstuvwxyz";

    void helper(TreeNode* root,string path){
        if (!root)return;

        path=alphabet[root->val]+path;
        if(!root->left
        &&!root->right){
            sm=min(sm,path);

        }
       helper(root->left, path);
        helper(root->right, path); 
    }
public:
    string smallestFromLeaf(TreeNode* root) {
              helper(root, "");
        return sm;  
    }
};