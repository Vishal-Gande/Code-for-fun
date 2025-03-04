// lc 386

// Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

// You must write an algorithm that runs in O(n) time and uses O(1) extra space.

bool mycomp(int a, int b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);

        return s1<s2;
    }

class Solution {
public:

    vector<int> lexicalOrder(int n) {

        vector<int>res;

        for(int i=1;i<=n;i++)
        {
            res.push_back(i);
        }

        sort(res.begin(),res.end(), mycomp);

        return res;


    }
};