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

//  lc_1372
//  You are given the root of a binary tree.

// A ZigZag path for a binary tree is defined as follow:

// Choose any node in the binary tree and a direction (right or left).
// If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
// Change the direction from right to left or from left to right.
// Repeat the second and third steps until you can't move in the tree.
// Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

// Return the longest ZigZag path contained in that tree.
class Solution {
public:
    void traversal(TreeNode* root, char dir , int &res, int count)
    {
        if(root!=NULL)
        {
            count++;
            res = max(res,count);

            if(dir == 'l')
            {
                traversal(root->right, 'r', res, count);
                traversal(root->left, 'l', res, 1);
            }
            else
            {
                traversal(root->left, 'l', res, count);
                traversal(root->right, 'r', res, 1);
            }

        }
    }
    int longestZigZag(TreeNode* root) {
        int res=1;
        int count=1;
        traversal(root->left, 'l', res,count);
        traversal(root->right, 'r', res,count);


        return res-1;

    }
};