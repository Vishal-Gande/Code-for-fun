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

//  lc 1161
//  Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.


class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> qu;

        qu.push(root);
        int maxi = INT_MIN;
        int res = 1;
        int level = 0;
        while(qu.size())
        {
            level++;
            int counter = qu.size();
            int sum = 0;
            while(counter){
                TreeNode* x = qu.front();
                if(x->left !=NULL) qu.push(x->left);
                if(x->right != NULL) qu.push(x->right);
                counter--;
                sum += x->val;
                qu.pop();
            }

            if(sum>maxi)
            {
                maxi = sum;
                res = level;
            }
        }

        return res;

    }
};