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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> preorder;
        std::stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode* p = stack.top();
            stack.pop();
            if (p != nullptr) {
                preorder.push_back(p->val);
                stack.push(p->right);
                stack.push(p->left);
            }
        }
        return preorder;
    }
};
