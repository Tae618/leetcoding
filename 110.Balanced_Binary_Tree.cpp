/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int caldepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int left = caldepth(root->left);
        int right = caldepth(root->right);
        if(left-right>1 || left-right<-1 || left<0 || right<0)
            return -1;
        return left>right?left+1:right+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        return caldepth(root)!=-1;
    }
};
