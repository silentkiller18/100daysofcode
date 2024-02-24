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
void fill ( vector<int> &v , TreeNode* root ) { 
        if ( root == NULL ) { 
            return ; 
        }
        v.push_back ( root -> val ) ; 
        fill ( v, root -> left ) ; 
        fill (v , root -> right ) ; 
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v ; 
        fill ( v , root ) ; 
        return v ; 
    }
};