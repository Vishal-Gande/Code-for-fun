//lc 108
// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.


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

    void attachnode(int first, int last, vector<int>&nums, TreeNode* p, string side)
    {
        int mid = (first+last)/2;

        //if(first+last % 2 != 0)  mid++;               // odd size

        if(first<=last)
        {
            TreeNode* next = new TreeNode(nums[mid]);

            if(side == "left") p->left = next;
            else    p->right = next;

            attachnode(first, mid-1, nums, next, "left");
            attachnode(mid+1, last, nums, next, "right");
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {

    int n=nums.size()-1;
    int mid = n/2;

    TreeNode* root = new TreeNode(nums[mid]);
    attachnode(0,mid-1,nums,root,"left");
    attachnode(mid+1, n, nums, root, "right" );

    return root;

    }
};