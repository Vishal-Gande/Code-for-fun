//lc 1652

// You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

// To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

// If k > 0, replace the ith number with the sum of the next k numbers.
// If k < 0, replace the ith number with the sum of the previous k numbers.
// If k == 0, replace the ith number with 0.
// As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

// Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

class Solution {
public:
    vector<int> decrypt(vector<int>& A, int k) {

        int n=A.size();
        vector<int>prefix;
        //prefix.push_back(0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum += A[i];
            prefix.push_back(sum);
        }

        vector<int>res(n,0);

        if(k>0)
        {
            for(int i=0;i<n;i++)
            {
                int index = i+k;
                if(index < n)
                {
                    res[i]=prefix[index]-prefix[i];
                }
                else
                {
                    int rem = k - (n-1-i);
                    cout<<rem<<endl;
                    res[i] = prefix[rem-1] + (prefix[n-1] - prefix[i]);
                }
            }
        }

        if(k<0)
        {
            k = -1*k;

            for(int i=1;i<n;i++)
            {
                int index = i-k-1;
                if(index >= 0)
                {
                    res[i]=prefix[i-1] - prefix[index];
                }
                else
                {
                    int rem = k-(i);
                    res[i] = prefix[i-1] + (sum - prefix[n-1 - rem]);
                }
            }
            res[0] = prefix[n-1] - prefix[n-k-1];
        }

        return res;
    }
};