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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == 0){
            return root;
        }
        if(root->val == NULL){
            return NULL;
        }
        // If both is smaller, then just traverse the left
        if (p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        // If both is bigger, than just traverse the right
        if (p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        // if they are in the different side, then the smallest is the root
        return root;
    }
};