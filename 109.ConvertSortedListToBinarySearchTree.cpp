/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//**** Strategy I  Nlog(N) ********
class Solution {
private:
    ListNode* getMiddle(ListNode* head)
    {
        //if(head==NULL) return head;
        ListNode* pre = head;
        ListNode* next = head;
        ListNode* cur = head;
        while(next!=NULL)
        {
            if(next->next==NULL)
                break;
            next=next->next;
            if(next->next==NULL)
                break;
            next=next->next;
            pre = cur;
            cur=cur->next;    
        }
        return pre;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        ListNode* pre = getMiddle(head);
        //cout<<pre->val<<endl;
        ListNode* cur = pre->next;
        if(cur==NULL)
            return new TreeNode(pre->val);
        TreeNode* root = new TreeNode(cur->val);
        ListNode* left = head;
        ListNode* right = cur->next;
        pre->next = NULL;
        root->left = sortedListToBST(left);
        root->right = sortedListToBST(right);
        return root;
    }
};

//** Strategy II log(N)**
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
     ListNode* cur = NULL;
private:
    TreeNode* buildTree(int start, int end)
    {
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode* left = buildTree(start,mid-1);
        TreeNode* root = new TreeNode(cur->val);
        cur= cur->next;
        root->right = buildTree(mid+1, end);
        root->left=left;
        return root;
    }
public:
   
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        int len=0;
        cur = head;
        while(head!=NULL)
        {
            len++;
            head=head->next;
        }
        return buildTree(0,len-1);
    }
};


