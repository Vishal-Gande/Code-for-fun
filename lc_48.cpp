// lc 48
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

class Solution {
public:
    void rotate(vector<vector<int>>& M) {

        int n = M.size();
        int m = M[0].size();


        for(int i=0;i<n;i++)
        {

            for(int j=0;j<m;j++)
            {

                int x = M[i][j];
                int temp_i = i;
                int temp_j = j;

                while(abs(x)<1000)
                {

                    int r_i = j;
                    int r_j = n-i-1;


                    int temp = M[r_i][r_j];
                    M[r_i][r_j]= x+1001; // to track that it's already done
                    x = temp;
                    i=r_i;
                    j=r_j;


                }
                i = temp_i;
                j=temp_j;

            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                M[i][j]=M[i][j]-1001;
            }
        }

    }
};