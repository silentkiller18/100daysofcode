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

    int possiblePathsSum (TreeNode* root, int &res){
        if(!root) return {-1001};
        int leftRes = possiblePathsSum(root->left, res);
        int rightRes = possiblePathsSum(root->right, res);
        int rootVal = root->val;
        int maxOfLeftAndRight = max(leftRes, rightRes);
        
        res = max({res, rootVal, rootVal + leftRes + rightRes, rootVal, maxOfLeftAndRight + rootVal});


        return max(rootVal, rootVal + maxOfLeftAndRight);

        
    }
    int maxPathSum(TreeNode* root) {
        int res = -1001;
        possiblePathsSum(root, res);

        return res;
    }
};