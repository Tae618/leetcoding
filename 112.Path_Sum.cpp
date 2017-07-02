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
    bool hasSum(TreeNode* root, int sum)
    {
        if(root==NULL) return false;
        if(sum==root->val && root->left==NULL && root->right==NULL)
            return true;
        
        if(hasSum(root->left, sum-(root->val)) || hasSum(root->right, sum-(root->val)))
        {
            //cout<<"left"<<endl;
            return true;
        }       
        
        return false;
        //return ( hasSum(root->left, sum - (root->val) ) || hasSum(root->right, sum - (root->val) ) );
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        
        return hasSum(root, sum);
    }
};
