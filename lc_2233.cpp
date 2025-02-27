// lc 2233

// You are given an array of non-negative integers nums and an integer k. In one operation, you may choose any element from nums and increment it by 1.

// Return the maximum product of nums after at most k operations. Since the answer may be very large, return it modulo 109 + 7. Note that you should maximize the product before taking the modulo.



// Example 1:

// Input: nums = [0,4], k = 5
// Output: 20
// Explanation: Increment the first number 5 times.
// Now nums = [5, 4], with a product of 5 * 4 = 20.
// It can be shown that 20 is maximum product possible, so we return 20.
// Note that there may be other ways to increment nums to have the maximum product.

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }

        long long int res =1;

        while(k)
        {
            int x = pq.top();
            x++;
            pq.pop();
            pq.push(x);
            k--;
        }

        while(pq.size())
        {
            res = (res*pq.top()) % 1000000007 ; // a mod x + b mod x == (a+b) mod x
            pq.pop();
        }

        return res % 1000000007;
    }
};