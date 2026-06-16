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

void recurse(TreeNode* root, int mx) {
    if (!root) {
        return;
    }
    if (root->val >= mx) {
        a++;
    }
    mx = max(mx, root->val);
    recurse(root->left, mx);
    recurse(root->right, mx);
}

class Solution {
public:
    int goodNodes(TreeNode* root) {
        a = 0;
        recurse(root, INT_MIN);
        return a;
    }
};
