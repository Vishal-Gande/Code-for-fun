
// LC 525 Contiguous array
// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.



// Example 1:

// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
// Example 2:

// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.


// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int maxi=0;

        int n=nums.size();
        map<int, vector<int> >mp; //sum,indices

        int sum = 0;
        //mp[0]=0;
        mp[0].push_back(-1); // corner case, storing state without first element, -1 to aid in line 30
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                sum--; // helps in checking equal 0s and 1s
            else
                sum++;

            mp[sum].push_back(i);
        }



        for(auto it = mp.begin();it!=mp.end();it++)
        {
            vector<int>temp = it->second;
            if(temp.back()-temp.front() > maxi)
            {
                maxi = temp.back()-temp.front();
            }

        }

        return maxi;

    }
};

// TC: nlogn, space: O(n)