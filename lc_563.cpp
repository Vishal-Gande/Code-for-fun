// lc 563

// Given the root of a binary tree, return the sum of every tree node's tilt.

// The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the node does not have a right child.

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
    int traverse(TreeNode* root, int sum,int &res)
    {
        if(root!=NULL)
        {
            int left_sum = traverse(root->left, sum, res);

            int right_sum = traverse(root->right, sum, res);

            res += abs(left_sum - right_sum);

            sum += root->val;


            return root->val + left_sum + right_sum;
        }
        return 0;
    }
    int findTilt(TreeNode* root) {

        int res = 0;
        traverse(root, 0, res);

        return res;
    }
};