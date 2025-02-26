// 1351
// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
// Example 1:

// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int res=0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {

            int index = lower_bound(grid[i].begin(),grid[i].end(),-1, greater<int>()) - grid[i].begin();
            cout<<index<<" "<<m;
            if(index<m)
            {
                res = res + m - index;
            }
        }

        return res;

    }
};