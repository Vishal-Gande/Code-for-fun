// lc 101
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


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
    void dfs(TreeNode* left, TreeNode* right, bool &flag)
    {
        if(left!= NULL && right!=NULL)
        {
            if(left->val != right->val) flag=false;

            dfs(left->left, right->right, flag);
            dfs(left->right, right->left, flag);
        }
        else{
            if(left==NULL && right !=NULL) flag=false;
            if(right==NULL && left != NULL) flag = false;
        }

    }
    bool isSymmetric(TreeNode* root) {

        bool flag = true;
        dfs(root->left, root->right, flag);

        return flag;

    }
};