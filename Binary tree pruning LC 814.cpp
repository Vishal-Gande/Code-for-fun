// Leetcode 814 Binary tree Pruning
// Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

// A subtree of a node node is node plus every node that is a descendant of node.
// Example 1:
// Input: root = [1,null,0,0,1]
// Output: [1,null,0,null,1]
// Explanation:
// Only the red nodes satisfy the property "every subtree not containing a 1".
// The diagram on the right represents the answer.


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

    bool dfs(TreeNode* root)
    {
        if(root != NULL)
        {
            bool f1 = dfs(root->left);
            bool f2 = dfs(root->right);

            if(f1 == false) root->left = NULL;
            if(f2 == false) root->right = NULL;

            if(root->val==1) return true;
            if(f1 || f2 ) return true;

            return false;
        }
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {

        dfs(root);
        if(root->left ==NULL && root->right==NULL)
        {
            if(root->val == 0)
            return NULL;
        }
        return root;

    }
};

// TC : O(n), SC : O(n) due to recursion stack which could reach upto depth of tree in worst case, avg SC is O(logn)