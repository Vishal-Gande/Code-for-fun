// lc 1493

// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.



class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int count=0;
        int n = nums.size();
        int left = 0, right=0;
        int res = 0;
        int zero_count = 0;
        if(nums[0]==0) zero_count++; // if first ele is zero

        for(left=0;left<n;left++)
        {
            //if(nums[left]==0) zero_count++;

            while(zero_count <=1 && right<n)
            {
                res = max(res, right-left-zero_count+1);
                right++;
                if(right<n && nums[right]==0) zero_count++;
            }
            if(nums[left]==0) zero_count--;
        }

        if(res==n) return n-1; // [1,1,1] case, deleting one element is mandatory
        return res;
    }
};