// 1503

//We have a wooden plank of the length n units. Some ants are walking on the plank, each ant moves with a speed of 1 unit per second. Some of the ants move to the left, the other move to the right.
//
//When two ants moving in two different directions meet at some point, they change their directions and continue moving again. Assume changing directions does not take any additional time.
//
//When an ant reaches one end of the plank at a time t, it falls out of the plank immediately.
//
//Given an integer n and two integer arrays left and right, the positions of the ants moving to the left and the right, return the moment when the last ant(s) fall out of the plank.
//


class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {

        // when they meet, they go on either sides, but the net change of ants is none
        int res=0,x;
        for(int i=0;i<left.size();i++)
        {
            x = left[i];
            if(x>res) res = x;
        }

        for(int i=0;i<right.size();i++)
        {
            x = right[i];
            if(n-x>res) res = n-x;
        }

        return res;

    }
};