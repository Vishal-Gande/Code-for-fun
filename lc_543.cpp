// lc 543

// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.
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
    int res=0;

    int dfs(TreeNode* root)
    {
        if(root!=NULL)
        {

            int left = dfs(root->left);
            int right = dfs(root->right);

            //cout<<root->val<<" "<<res<<endl;
            res = max(res, left+right+1);
            return max(left,right)+1 ;
        }
        return 0;
    }
    int diameterOfBinaryTree(TreeNode* root) {

        res = max(res, dfs(root));

        return res-1;

    }
};