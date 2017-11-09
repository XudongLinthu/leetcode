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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> postorder;
        std::stack<std::pair<TreeNode*, bool>> stack;
        stack.push(std::make_pair(root, false));
        while (!stack.empty()) {
            auto pair = stack.top();
            stack.pop();
            TreeNode* p = pair.first;
            if (p == nullptr) {
                continue;
            }
            if (!pair.second) {
                stack.push(std::make_pair(p, true));
                stack.push(std::make_pair(p->right, false));
                stack.push(std::make_pair(p->left, false));
            } else {
                postorder.push_back(p->val);
            }
        }
        return postorder;
    }
};
