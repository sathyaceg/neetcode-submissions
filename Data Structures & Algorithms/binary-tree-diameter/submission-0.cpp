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

int a = 0;

int recurse(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int lh = recurse(root->left);
    int rh = recurse(root->right);
    a = max(a, lh + rh);
    return max(lh, rh) + 1;
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        a = 0;
        recurse(root);
        return a;
    }
};
