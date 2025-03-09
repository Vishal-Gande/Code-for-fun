// lc 236
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res;

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q, bool flag1, bool flag2, bool &flag)
    {
        if(flag && root!=NULL)
        {
            bool found1 = dfs(root->left, p,q,flag1,flag2,flag);
            bool found2 = dfs(root->right, p,q,flag1,flag2, flag);

            if(found1 && found2)
            {
                flag = false; // dont check further
                res = root;
            }
            if(found1 && (root==p || root==q))
            {
                flag = false; // dont check further
                res = root;
            }
            if(found2 && (root==p || root==q))
            {
                flag = false; // dont check further
                res = root;
            }

            return found1 || found2 || root==p || root==q;

        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        bool flag1=false, flag2=false, flag=true;
        dfs(root,p,q,flag1,flag2,flag);
        return res;

    }
};