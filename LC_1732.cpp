//lc_1732

// There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

// You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int res = 0;
        int curr_alt=0;
        for(int i=0;i<gain.size();i++)
        {
            curr_alt += gain[i];

            if(curr_alt > res) res = curr_alt;
        }

        return res;

    }
};