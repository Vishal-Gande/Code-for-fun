// lc 162

// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n= nums.size();
        int left=0,right=n-1;

        while(right - left >1)
        {
            int index = (left+right)/2;

            int x = nums[index];

            if(x>nums[index+1])
            {
                right = index;
            }
            else
            {
                left = index+1;
            }
        }

        if(nums[left]>nums[right]) return left;
        else return right;
    }
};


// implemented above soln after reading this

// When people see ths question, I think most people will immediately come up with the linear search solution, which is to examine each num and compare it with its two neighbours. No braniner, right? Then people are thinking why this kind of question would appear in the question pool and why it's even rated as Medium. Then they might go to the Solution tab and see someone writing up a big article explaining a better solution and probably think, why bother? That's an overkill.

// These types of questions are so undervalued by people. And these are the questions we should pay more attention to. I'm sure in a real question, the interviewer will not be satisfied by the linear solution. Why? Because the straightforward linear scan solution isn't using all of the clues given in the question. These clues, including

// No adjacent two numbers are the same
// the two end of the arrays are -∞
// You can return any peak.
// are all the clues that we can base upon to get to the final BS solution. When you are reading a question, pay great attention to these clues. If your solution does not involve all of the clue provided, you might not get the optimal solution. This is not any random question, it's asked by Facebook, Google, etc., for multiple times. There is a reason why it exist and please don't downvote it without even attempting to understand it.