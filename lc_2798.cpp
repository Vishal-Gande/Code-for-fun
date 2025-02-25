

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& h, int target) {

        int n = h.size();
        sort(h.begin(),h.end());
        if(h[n-1]<target) return 0;

        int index = lower_bound(h.begin(),h.end(),target)-h.begin();

        int res = n - index;

        return res;

    }
};