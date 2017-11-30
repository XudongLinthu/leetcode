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
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
private:
    std::pair<bool, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return std::make_pair(true, 0);
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if (left.first == false || right.first == false) {
            return std::make_pair(false, 0);
        } else {
            if (std::abs(left.second - right.second) <= 1) {
                return std::make_pair(true, std::max(left.second, right.second) + 1);
            } else {
                return std::make_pair(false, 0);
            }
        }
    }
};
