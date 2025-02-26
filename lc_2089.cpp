// 2089

// You are given a 0-indexed integer array nums and a target element target.

// A target index is an index i such that nums[i] == target.

// Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.
// Example 1:

// Input: nums = [1,2,5,2,3], target = 2
// Output: [1,2]
// Explanation: After sorting, nums is [1,2,2,3,5].
// The indices where nums[i] == 2 are 1 and 2.

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        int n=nums.size();
        vector<int>res;
        sort(nums.begin(),nums.end());

        int index = lower_bound(nums.begin(),nums.end(), target) - nums.begin();

        if(index>=n) return res;

        while(index<n && nums[index]==target)
        {
            res.push_back(index);
            index++;
        }

        return res;

    }
};