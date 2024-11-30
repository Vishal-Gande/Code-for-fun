// Leetcode 357 Count numbers with unique digits
//Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.
// Example 1:

// Input: n = 2
// Output: 91
// Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {

        if(n==0) return 1;
        if (n==1) return 10;

        int initial = 10;
        int sum = 9;
        int multiplier = 9;
        int res = 10;
        while(n>=2)
        {
            sum = 9;
            multiplier = 9;
            for(int i=n;i>1;i--)
            {
                sum = sum*multiplier;
                multiplier--;
            }

            cout<<sum<<endl;

            res += sum;
            n--;
        }

        return res;

    }
};

//TC - O(n^2), SC- O(1)