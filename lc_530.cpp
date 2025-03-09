// lc 530
// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.


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
    void traversal(TreeNode* root, int &mini , int &prev)
    {
        if(root!=NULL)
        {
            traversal(root->left, mini, prev);
            int curr = root->val;

            if(prev!=INT_MAX) mini = min(mini, abs(curr-prev));

            prev = curr;
            traversal(root->right, mini, prev);

        }

        //return INT_MAX;
    }
    int getMinimumDifference(TreeNode* root) {

        //set<int>mp;
        int mini = INT_MAX;
        int prev = INT_MAX;
        traversal(root, mini, prev);

        return mini;
    }
};