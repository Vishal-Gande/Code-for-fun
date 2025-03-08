// lc 1937

// You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

// To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

// However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

// Return the maximum number of points you can achieve.

class Solution {
public:
    long long maxPoints(vector<vector<int>>& P) {

        int n = P.size();
        int m = P[0].size();
        vector<long long >prev(m);
        for(int i=0;i<m;i++)
            prev[i]=P[0][i];

        vector<long long >dp(m);

        for(int i=1;i<n;i++)
        {

            for(int j=0;j<m;j++)
            {
                long long prev_maxi=0;
                for(int k=0;k<m;k++)
                {
                    prev_maxi = max(prev_maxi, prev[k]-abs(k-j));
                }
                //dp.push_back(prev_maxi+P[i][j]);
                dp[j] = prev_maxi + P[i][j];
            }
            prev = dp;
            //dp.clear();
        }
        long long res=0;
        for(int i=0;i<m;i++)
        {
            res= max(res,prev[i]);
        }

        return res;

    }
};