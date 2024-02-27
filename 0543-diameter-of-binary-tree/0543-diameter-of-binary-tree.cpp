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
    int solve(TreeNode* root, int &result) {
        if (!root) {
            return 0;
        }
        int a = solve(root->left, result);
        int b = solve(root->right, result);
        result = max(result, a + b);
        return 1 + max(a, b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int result = INT_MIN;
        solve(root, result);
        return result;
    }
};