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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q;
        map<int, vector<int>> m;
        vector<vector<int>> a;

        if (!root) {
            return a;
        }

        q.push({root, 0});
        while(!q.empty()) {
            TreeNode* current = q.front().first;
            int level = q.front().second;
            q.pop();

            m[level].push_back(current->val);
            if (current->left) {
                q.push({current->left, level + 1});
            }
            if (current->right) {
                q.push({current->right, level + 1});
            }
        }

        for (int i = 0; ; ++i) {
            if (m.find(i) == m.end()) {
                break;
            }
            a.push_back(m[i]);
        }
        return a;

    }
};
