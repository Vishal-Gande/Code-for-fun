//LC 1304. FInd N unique integers sum up to zero
class Solution {
public:
    vector<int> sumZero(int n) {

        vector<int>res;
        for(int i=1;i<n;i++)
        {
            res.push_back(i);
        }

        res.push_back((n*(n-1))/-2);

        return res;

    }
};