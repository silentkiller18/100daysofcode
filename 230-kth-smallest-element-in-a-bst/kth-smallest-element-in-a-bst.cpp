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

  void inorder(TreeNode* n,int &cnt,int k,int& ans){

        if(n==NULL)return;

        inorder(n->left,cnt,k,ans);

        cnt++;

        if(cnt==k) {

            ans=n->val;

            return;

        }

        inorder(n->right,cnt,k,ans);

    }

 

int kthSmallest(TreeNode *root, int k)

{

    int ans=-1;

        int cnt=0;

       inorder(root,cnt,k,ans);

        return ans;

}


};