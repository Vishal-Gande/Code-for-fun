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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;
        if(root==NULL) return res;
        
        queue<TreeNode* > qu;
        qu.push(root);
        vector<int>each_lvl;

        while(qu.size()){

            int counter = qu.size();
            each_lvl.clear();

            while(counter){
                TreeNode* p = qu.front();
                each_lvl.push_back(p->val);
                if(p->left!=NULL) qu.push(p->left);
                if(p->right!=NULL) qu.push(p->right);
                qu.pop();
                counter--;
            }

            res.push_back(each_lvl);
        }

        return res;
        
    }
};
