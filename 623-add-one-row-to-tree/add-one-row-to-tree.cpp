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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //base case

        if(depth==1){
            return new TreeNode(val,root,NULL);
        }
//DFS

helper(root,val,depth,1);
return root;

    }
private:
void helper(TreeNode* node,int val,int depth,int cdepth){
    if(node==NULL)return;

    if(cdepth==(depth-1)){
        node->left=new TreeNode(val,node->left,NULL);
        node->right=new TreeNode(val,NULL,node->right);
        return;
    }

helper(node->left,val,depth,cdepth+1);
helper(node->right,val,depth,cdepth+1);

}



};