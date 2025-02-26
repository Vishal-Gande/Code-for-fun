// // lc_209
// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.



// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n=nums.size(), c = 0;
        int res=INT_MAX;
        int left = 0, right=-1;
        int sum=0, i=0;

        while(right<n-1)
        {
            right++;
            sum += nums[right];

            while(sum >= target)
            {
                res = min(res, right-left+1);
                sum = sum - nums[left];
                left++;
            }
        }
        if(res==INT_MAX) return 0;
        return res;

    }
};