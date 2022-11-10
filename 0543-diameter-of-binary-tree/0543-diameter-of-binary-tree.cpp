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
    int h1(TreeNode* root)
    {
        if(root == NULL) return 0;
        return max(h1(root->left), h1(root->right))+1;
    }
    int h2(TreeNode* root)
    {
        if(root == NULL) return 0;
        return max(h2(root->left), h2(root->right))+1;
    }
    void traverse(TreeNode* root, int &ans)
    {
        if(root == NULL) return;
        traverse(root->left, ans);
        ans = max(ans, h1(root->left)+h2(root->right));
        traverse(root->right, ans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        traverse(root, ans);
        return ans;
    }
};