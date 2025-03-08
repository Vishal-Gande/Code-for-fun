// lc 994
// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        bool flag = false;
        int minutes=0;
        vector<vector<int>> g2(grid);

        while(minutes==0 || flag ==false)
        {
            flag=true;
            g2 = grid;
            minutes++;

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    int x = grid[i][j];
                    if(x==1)
                    {
                        flag=false;
                        bool possible=false;
                        int count =0;
                        if(i+1<n && grid[i+1][j] != 0) possible=true;
                        if(i-1 >=0 && grid[i-1][j]!=0) possible=true;
                        if(j+1<m && grid[i][j+1]!=0) possible=true;
                        if(j-1>=0 && grid[i][j-1]!=0) possible=true;

                        if(possible==false) return -1; // not possible to rot case
                    }

                    if(x==2)
                    {
                        if(i+1<n && grid[i+1][j]==1) g2[i+1][j]=2;
                        if(i-1 >=0 && grid[i-1][j]==1) g2[i-1][j]=2;

                        if(j+1<m && grid[i][j+1]==1) g2[i][j+1] = 2;
                        if(j-1>=0 && grid[i][j-1]==1) g2[i][j-1] = 2;
                    }
                }
            }
            if(grid == g2 && flag == false) return -1;
            grid = g2;
        }

        return minutes-1;



    }
};