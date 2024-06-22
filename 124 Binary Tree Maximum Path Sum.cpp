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
    int mx = -1e9;
    int func(TreeNode*root){
        if(root==NULL){
            return 0;
        }

        int l = func(root->left);
        int r = func(root->right);

        if(l < 0) l = 0;
        if(r < 0) r = 0;
        
        int a = root->val + l + r;
        mx = max(mx,a);
        return max(root->val+l,root->val+r);
    }
    int maxPathSum(TreeNode* root) {
        mx = -1e9;
        func(root);
        return mx;
    }
};