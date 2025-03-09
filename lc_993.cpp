// lc 993
// Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.


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
    void dfs(TreeNode* root, int x, int y, int &depth_x, int &depth_y, int cur_depth, int &x_p, int &y_p, int p)
    {
        if(root!=NULL)
        {
            int value = root->val;

            if(value == x)
            {
                depth_x = cur_depth;
                x_p = p;
            }
            if(value == y)
            {
                depth_y = cur_depth;
                y_p = p;
            }

            cur_depth++;

            dfs(root->left, x, y, depth_x, depth_y, cur_depth, x_p, y_p, value);
            dfs(root->right, x, y, depth_x, depth_y, cur_depth, x_p, y_p, value);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {

        int depth_x, depth_y, cur_depth = 0, x_p = -1 , y_p = -2, p=-3 ;
        dfs(root, x, y, depth_x, depth_y, cur_depth, x_p, y_p, p);

        return depth_x == depth_y && x_p != y_p ;

    }
};