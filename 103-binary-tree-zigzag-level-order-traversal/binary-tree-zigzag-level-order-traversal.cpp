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
vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i =0; i<n; i++){
                TreeNode *x = q.front();
                q.pop();
                if(x->left!=nullptr) q.push(x->left);
                if(x->right!=nullptr) q.push(x->right);
                level.push_back(x->val);
            }
            ans.push_back(level);
        }
        return ans;
}
void reverse(vector<int> &v){
     int n = v.size();
     for(int i=0; i<n/2; i++){
         swap(v[i],v[n-1-i]);
     }
}
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> ans = levelOrder(root);
        int n = ans.size();
        for(int i=0; i<n; i++){
            if(i&1) reverse(ans[i]);
        }
    return ans;
    }
};