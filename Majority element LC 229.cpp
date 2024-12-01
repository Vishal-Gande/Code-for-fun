// 229. Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.



// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]


// Constraints:

// 1 <= nums.length <= 5 * 104
// -109 <= nums[i] <= 109


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n=nums.size();
        map<int,int>mp; //num and freq

        vector<int>res;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        for(auto it = mp.begin();it!=mp.end();it++)
        {
            if(it->second > n/3) res.push_back(it->first);
        }

        return res;

    }
};