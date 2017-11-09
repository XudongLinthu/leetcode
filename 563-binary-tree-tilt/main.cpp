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
    int findTilt(TreeNode* root) {
        return dfs(root).first;
    }

private:
    std::pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return std::make_pair(0, 0);
        }

        int leftTilt, rightTilt;
        int leftSum, rightSum;

        auto leftRes = dfs(root->left);
        auto rightRes = dfs(root->right);

        leftTilt = leftRes.first;
        leftSum = leftRes.second;
        rightTilt = rightRes.first;
        rightSum = rightRes.second;

        int tilt = leftTilt + rightTilt + std::abs(leftSum - rightSum);
        int sum = leftSum + rightSum + root->val;

        return std::make_pair(tilt, sum);
    }
};
