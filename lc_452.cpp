// lc_452

// There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

// Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

// Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& P) {

        int n = P.size();
        sort(P.begin(),P.end());

        vector<vector<int>> merged;

        for(int i=0;i<n;i++)
        {
            vector<int>temp(P[i]);
            bool flag = true;

            while(i+1<n && temp[1] >= P[i+1][0])
            {
                temp[1] = min(temp[1], P[i+1][1]);
                temp[0] = max(temp[0], P[i+1][0]);
                i++;
                flag=false;
            }

            cout<<temp[0]<<" "<<temp[1]<<endl;
            merged.push_back(temp);

            //if(flag==false) i--; // to offset extra i++ that happens in the end
        }

        return merged.size();

    }
};