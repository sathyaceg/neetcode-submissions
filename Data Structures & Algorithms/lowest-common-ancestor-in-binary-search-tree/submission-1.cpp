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

TreeNode* a;

bool recurse(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
        return false;
    }
    cout << "VAL: " << root->val << '\n';
    bool ret1 = recurse(root->left, p, q);
    bool ret2 = recurse(root->right, p, q);
    if (ret1 && ret2 && a == NULL) {
        a = root;
    }
    if ((ret1 || ret2) && (root->val == p->val || root->val == q->val) && a == NULL) {
        a = root;
    }
    return (ret1 || ret2 || root->val == p->val || root->val == q->val);
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        a = NULL;
        recurse(root, p, q);
        return a;
    }
};
