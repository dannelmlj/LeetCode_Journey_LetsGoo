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
    int out = 0;
    int totalDepth(TreeNode* root){
        if (root == NULL)
            return 0;
        else {

            int lDepth = totalDepth(root->left);
            int rDepth = totalDepth(root->right);
    
            out = max(out, lDepth + rDepth);
            return 1+ max(lDepth , rDepth);
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        totalDepth(root);
        return out;
    }
};