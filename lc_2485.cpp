// lc 2485
// Given a positive integer n, find the pivot integer x such that:

// The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
// Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

class Solution {
public:
    int pivotInteger(int n) {

        vector<int>prefix;
        prefix.push_back(0);
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            sum += i;
            prefix.push_back(sum);
        }

        for(int i=1;i<=n;i++)
        {
            if(prefix[i]==sum-prefix[i-1])
                return i;
        }

        return -1;

    }
};