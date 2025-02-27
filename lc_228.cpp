// //lc 228
// You are given a sorted unique integer array nums.

// A range [a,b] is the set of all integers from a to b (inclusive).

// Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

// Each range [a,b] in the list should be output as:

// "a->b" if a != b
// "a" if a == b


// Example 1:

// Input: nums = [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: The ranges are:
// [0,2] --> "0->2"
// [4,5] --> "4->5"
[7,7] --> "7"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string>res;

        int n = nums.size();
        if(n==0) return res;
        int start = nums[0], prev=nums[0];
        int last;

        for(int i=1;i<n;i++)
        {
            int x = nums[i];
            if(x-1==nums[i-1])
            {
                prev = nums[i];
            }
            else
            {
                string s;
                if(start!=nums[i-1])
                {
                    s = to_string(start);
                    s += "->";
                    s += to_string(nums[i-1]);
                }
                else
                {
                    s = to_string(start);
                }
                res.push_back(s);
                start = nums[i];
                prev = nums[i];
            }
        }
        string s;
        if(start==prev)
        {
            cout<<"yes";
            res.push_back(to_string(start));
        }
        else
        {
            cout<<"NO";
            s = to_string(start);
            s += "->";
            s += to_string(prev);
            res.push_back(s);
        }

        return res;

    }
};