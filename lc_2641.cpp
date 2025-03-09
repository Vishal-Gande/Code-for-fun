// lc 2641
// Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Return the root of the modified tree.

// Note that the depth of a node is the number of edges in the path from the root node to it.

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
//unordered_map<int,int>mpd; // depth, sum of all cousins
//map< pair<int, TreeNode* >, int> mpp;

class Solution {
public:
    unordered_map<int,int>mpd; // depth, sum of all cousins
    unordered_map< TreeNode* ,int> mpp;

    void dfs(TreeNode* root, int d, TreeNode* parent)
    {
        if(root!=NULL)
        {
            int x = root->val;


            mpd[d] += x;


            //pair p = make_pair(d,parent);

            mpp[parent] += x;


            dfs(root->left, d+1, root);
            dfs(root->right, d+1, root);
        }
    }

    void markdfs(TreeNode* root, int depth, TreeNode* parent)
    {
        if(root != NULL)
        {
            if(depth < 2)
            {
                root->val = 0;
            }
            else
            {

                root->val = mpd[depth] - mpp[parent];
            }

            markdfs(root->left, depth+1, root);
            markdfs(root->right, depth+1, root);
        }
    }


    TreeNode* replaceValueInTree(TreeNode* root) {

        dfs(root, 0, root);

        markdfs(root, 0, root);

        root->val = 0;

        return root;


    }
};