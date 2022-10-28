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
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right) return true;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size())
        {
            int k = q.size();
            vector<int>v;
            for(int i = 0; i<k; i++)
            {
                auto curr = q.front();
                q.pop();
                if(curr->left)
                {
                    q.push(curr->left);
                    v.push_back(curr->left->val);
                }
                else v.push_back(101);
                if(curr->right)
                {
                    q.push(curr->right);
                    v.push_back(curr->right->val);
                }
                else v.push_back(101);
            }
            for(int i = 0; i<v.size()/2; i++)
            {
                if(v[i] != v[v.size()-i-1]) return false;
            }
        }
        return true;
    }
};