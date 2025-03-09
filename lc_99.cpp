// // lc 99
// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

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
    vector<int>A;
    void inorder(TreeNode* root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            A.push_back(root->val);
            inorder(root->right);
        }
    }

    void dfs(TreeNode* root, int &x, int &y)
    {
        if(root!=NULL)
        {
            int value = root->val;
            if(value == x)
            {
                root->val = y;
            }
            else if(value == y)
            {
                root->val = x;
            }

            dfs(root->left, x,y);
            dfs(root->right, x , y);
        }
    }
    void recoverTree(TreeNode* root) {

        inorder(root);

        vector<int>curr(A);

        sort(A.begin(),A.end());

        bool flag = true;
        int x,y;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=curr[i])
            {
                if(flag)
                {
                    x = A[i];
                    flag = false;
                }
                else y = A[i];
            }
        }

        dfs(root,x,y);



    }
};