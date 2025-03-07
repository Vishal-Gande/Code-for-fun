// lc 69
// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
class Solution {
public:
    int mySqrt(int A) {

        long long   left = 0;
        long long right = A;



        while(left<right)
        {
            long long x = (left+right)/2;

            if(x*x < A)
            {
                left = x+1;
            }
            else
            {
                right = x;
            }
        }

        if(left*left == A) return left;

        return left-1;



    }
};