// lc_77

// iven two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.



class Solution {
public:

    void backtrack(int i, int n, int k, vector<vector<int>> &res, vector<int>&x )
    {
        if(i<=n && x.size()<k)
        {
            x.push_back(i);

            if(x.size()==k) res.push_back(x);

            backtrack(i+1,n,k,res,x);
            x.pop_back();
            backtrack(i+1,n,k,res,x);
        }
    }
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> res;

        vector<int>x;
        backtrack(1,n,k,res,x);

        return res;

    }
};