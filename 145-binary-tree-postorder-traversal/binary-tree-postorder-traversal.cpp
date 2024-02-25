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
    private: vector<int> v;
public:

        void post(TreeNode* root){
        if(root!=NULL){
            post(root->left);
            post(root->right);
            v.push_back(root->val);
           
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
     post(root);
        return v;
    }
};