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

pair<int, int> recurse(TreeNode* root) {
    if (!root) {
        return {INT_MAX, INT_MIN};
    }
    pair<int, int> l = recurse(root->left);
    pair<int, int> r = recurse(root->right);
    int l_mn = l.first;
    int l_mx = l.second;
    int r_mn = r.first;
    int r_mx = r.second;

    a &= (root->val > l_mx) || (l_mx == INT_MIN);
    a &= (root->val < r_mn) || (r_mn == INT_MAX);

    pair<int, int> ret;
    ret.first = min(root->val, min(l.first, r.first));
    ret.second = max(root->val, max(l.second, r.second));
    return ret;
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        a = true;
        recurse(root);
        return a;
    }
};
