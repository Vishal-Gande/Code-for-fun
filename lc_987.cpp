// lc 987

// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.

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
    vector<vector<int>> cords; // x,y, val

    void dfs(TreeNode* root, int x, int y)
    {
        if(root!=NULL)
        {
            int value = root->val;
            vector<int>temp;
            temp.push_back(x);
            temp.push_back(y);
            temp.push_back(value);
            cords.push_back(temp);

            dfs(root->left, x+1, y-1);
            dfs(root->right, x+1, y+1);
        }
    }

    bool static mycomp(vector<int>a, vector<int>b)
    {
        if(a[1] != b[1])
            return a[1]<b[1];

        if(a[0] != b[0])
        {
            return a[0]<b[0];
        }
        else return a[2] < b[2];

    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        dfs(root,0,0);

        sort(cords.begin(), cords.end(), mycomp);

        vector<vector<int>> res;
        vector<int>temp;

        int n =cords.size();
        int prev_col = cords[0][1];
        for(int i=0;i<n;i++)
        {
            if(cords[i][1]==prev_col)
            {
                temp.push_back(cords[i][2]);
            }
            else
            {
                res.push_back(temp);
                temp.clear();
                temp.push_back(cords[i][2]);
                prev_col = cords[i][1];

            }
        }

        if(temp.size()) res.push_back(temp);

        return res;


    }
};