// LC 373. Find K Pairs with Smallest Sums

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k) {

        int n = A.size();
        vector<int>index(n,0);
        vector<vector<int>> res;

        for(int l=1;l<=k;l++)
        {
            int mini = INT_MAX;
            vector<int>temp(2,0);
            for(int i=0;i<n;i++)
            {
                int j = index[i];
                if(j<B.size() && A[i] + B[j] < mini)
                {
                    index[i]++;
                    temp[0]=A[i];
                    temp[1]=B[j];
                    mini = A[i] + B[j];
                }
            }
            res.push_back(temp);

        }

        return res;


    }
};