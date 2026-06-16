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

vector<int> a;
int mx = 0;

void recurse(TreeNode* root, int level) {
    if (!root) {
        return;
    }
    if (level > mx) {
        mx = level;
        a.push_back(root->val);
    }
    recurse(root->right, level + 1);
    recurse(root->left, level + 1);
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        a.clear();
        mx = 0;
        recurse(root, 1);
        return a;
    }
};
