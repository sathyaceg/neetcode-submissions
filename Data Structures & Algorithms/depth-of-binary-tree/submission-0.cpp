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

int recurse(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int lh = recurse(root->left);
    int rh = recurse(root->right);
    return max(lh, rh) + 1;
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int a = recurse(root);
        return a;
    }
};
