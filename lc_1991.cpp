//lc_1991
// Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).

// A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].

// If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.

// Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.



class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {

        vector<int>left;
        left.push_back(0);

        vector<int>right;
        int sum=0;

        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            left.push_back(sum);
        }

        int total = sum;

        for(int i=0;i<nums.size();i++)
        {
            right.push_back(total-left[i]);
        }

        right.push_back(0);

        for(int i=0;i<nums.size();i++)
        {
            if(left[i]==right[i+1])
            {
                return i;
            }
        }


        return -1;


    }
};