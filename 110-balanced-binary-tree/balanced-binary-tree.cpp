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
    bool out = true;
    int depth(TreeNode* root){
        if (root == NULL)
            return 0;
        else {
            int lDepth = depth(root->left);
            int rDepth = depth(root->right);
            int big = max(lDepth, rDepth);
            int small = min(lDepth, rDepth);
            int dif = big - small;

            if (dif > 1){
                out = false;
            }
            return 1 + max(lDepth , rDepth);
        }
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        depth(root);
        return out;

    }
};