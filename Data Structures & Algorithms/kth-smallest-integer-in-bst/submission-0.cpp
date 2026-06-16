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

int r = 1;
int a;

void recurse(TreeNode* root, int k) {
    if (!root) {
        return;
    }
    recurse(root->left, k);
    if (r == k) {
        a = root->val;
    }
    r++;
    recurse(root->right, k);
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        a = -1;
        r = 1;
        recurse(root, k);
        return a;
    }
};
