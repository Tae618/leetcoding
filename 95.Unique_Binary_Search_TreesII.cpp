/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
It's a dynamic planning problem.
root->left: all the valid trees in which all the elements are lower than root
root->right: all the valid trees in which all the elements are greater than root 
*/
class Solution {
private:
    vector<TreeNode*> search(int start, int end)
    {
        vector<TreeNode*> res;
        if(start>end)
        {
            res.push_back(NULL);
            return res;
        }
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> left = search(start,i-1);
            vector<TreeNode*> right = search(i+1, end);
            for(int k=0;k<left.size();k++)
            {
                for(int j=0;j<right.size();j++)
                {
                    TreeNode* p = new TreeNode(i);
                    p->left = left[k];
                    p->right = right[j];
                    res.push_back(p);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n<1)
            return res;
        return search(1,n);
    }
};
