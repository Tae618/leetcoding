/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * pay attention to the reference of parameters. if not, it will lead to memory out.
 */

class Solution {
private:
    TreeNode* building(vector<int>& preorder, vector<int>& inorder, int pa, int pb, int ia,int ib)
    {
        if(pa>pb) return NULL;

        if(pa==pb) 
            return new TreeNode(preorder[pa]);
        
        TreeNode* root = new TreeNode(preorder[pa]);
        int i=ia;
        for(;i<=ib;i++)
        {           
            if(inorder[i]==preorder[pa])
                break; 
        }
        int len = i-ia;
        root->left = building(preorder, inorder, pa+1,pa+len,ia,ia+len-1);
        root->right = building(preorder, inorder, pa+len+1,pb, ia+len+1,ib);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //if(preorder.size()==0) return NULL;
        return building(preorder, inorder,0, preorder.size()-1, 0, inorder.size()-1);
        //return root;
    }
};
