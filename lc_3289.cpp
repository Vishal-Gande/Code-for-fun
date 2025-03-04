// lc 3289
// In the town of Digitville, there was a list of numbers called nums containing integers from 0 to n - 1. Each number was supposed to appear exactly once in the list, however, two mischievous numbers sneaked in an additional time, making the list longer than usual.

// As the town detective, your task is to find these two sneaky numbers. Return an array of size two containing the two numbers (in any order), so peace can return to Digitville.

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {

        int n = nums.size();
        vector<int>check(n-2,-1);
        vector<int>res;

        for(int i=0;i<n;i++)
        {
            if(check[nums[i]]!= -1)
            {
                res.push_back(nums[i]);
            }
            else
                check[nums[i]]= -2;
        }

        return res;

    }
};