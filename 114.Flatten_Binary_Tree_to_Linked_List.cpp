/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 1.change left and right, travel right;
 * 2.back;
 * 3.traver left, set left node to NULL.
 */
class Solution {
TreeNode* res= new TreeNode(-1);
private:
    void inorder_traversal(TreeNode* root)
    {
        if(root==NULL) return;
        //res->right = root;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        res->right=root;
        res = res->right;
        inorder_traversal(root->right);
        inorder_traversal(root->left);
        root->left = NULL;
        
        return; 
    }
    
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = res;
        inorder_traversal(root);
        root = cur->right;
    }
};
