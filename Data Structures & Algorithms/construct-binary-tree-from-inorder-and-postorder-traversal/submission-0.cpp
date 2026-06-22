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

unordered_map<int, int> m;
int in = 0;

TreeNode* recurse(vector<int>& postorder, int left, int right) {
    if (left > right) {
        return NULL;
    }
    int value = postorder[in];
    in--;
    TreeNode* root = new TreeNode(value);
    root->right = recurse(postorder, m[value] + 1, right);
    root->left = recurse(postorder, left, m[value] - 1);
    return root;
}

void build_indices(vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
        m[inorder[i]] = i;
    }
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        m.clear();
        in = postorder.size() - 1;
        build_indices(inorder);
        TreeNode* a = recurse(postorder, 0, in);
        return a;
    }
};