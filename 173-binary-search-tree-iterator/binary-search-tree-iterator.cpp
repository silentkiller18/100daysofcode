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
class BSTIterator {
public:
    TreeNode*c=new TreeNode();
    stack<int>s;
    void ino( TreeNode*root) {
        if(root==NULL) return;
        if(root->right) ino(root->right);
        c=root;
        s.push(root->val);
        if(root->left) ino(root->left);
    }
    BSTIterator(TreeNode* root) {
        ino(root);
    }
    
    int next() {
        int n=s.top();
        s.pop();
        return n;
    }
    
    bool hasNext() {
        if(s.size()>0) return 1;
        return 0; 
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */