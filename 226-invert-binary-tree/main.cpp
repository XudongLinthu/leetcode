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
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            invert(root);
        }
        return root;
    }
private:
    void invert(TreeNode* root) {
        TreeNode* tmp;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        if (root->left) {
            invertTree(root->left);
        }
        if (root->right) {
            invertTree(root->right);
        }
    }
};
