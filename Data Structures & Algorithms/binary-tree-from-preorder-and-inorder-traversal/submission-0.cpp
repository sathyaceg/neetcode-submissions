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
int index = 0;

TreeNode* recurse(vector<int> &preorder, int left, int right) {
    if (left > right) {
        return NULL;
    }
    int value = preorder[index];
    TreeNode* root = new TreeNode(value);
    ++index;
    root->left = recurse(preorder, left, m[value] - 1);
    root->right = recurse(preorder, m[value] + 1, right);
    return root;
}

void build_indices(vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
        m[inorder[i]] = i;
    }
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        m.clear();
        index = 0;
        build_indices(inorder);
        TreeNode* a = recurse(preorder, 0, inorder.size() - 1);
        return a;
    }
};
