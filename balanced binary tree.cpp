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

    int traverse(TreeNode* root, int h, bool &flag)
    {
        if(root!=NULL)
        {

        int left_h = traverse(root->left, h, flag);
        int right_h = traverse(root->right,h, flag);
        if (abs(left_h-right_h)>1) flag=false;
        
        return max(left_h+1, right_h+1);
        }
    }
    bool isBalanced(TreeNode* root) {
        int h=0;
        bool flag=true;
        traverse(root,h,flag);

        return flag;
    }
};
