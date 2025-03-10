// lc 279
// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

class Solution {
public:
    int numSquares(int n) {

        vector<int>res(n+1,INT_MAX);
        res[0] = 0;
        res[1] = 1;

        for(int i=2;i<=n;i++)
        {

            for(int j = 1; j<=n;j++)
            {

                if(i - (j*j) >= 0)
                {
                    if(res[i - (j*j)]!= INT_MAX)
                    {

                        res[i] = min(res[i], res[i - j*j] +1);
                    }
                }
                else break;

            }
        }

        return res[n];
    }
};