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

bool a = true;

int recurse(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int lh = recurse(root->left);
    int rh = recurse(root->right);
    a &= (abs(lh - rh) <= 1);
    return max(lh, rh) + 1;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        a = true;
        recurse(root);
        return a;
    }
};
