// LC 2952
//2952. Minimum Number of Coins to be Added
//Attempted
//Medium
//Topics
//Companies
//Hint
//You are given a 0-indexed integer array coins, representing the values of the coins available, and an integer target.
//
//An integer x is obtainable if there exists a subsequence of coins that sums to x.
//
//Return the minimum number of coins of any value that need to be added to the array so that every integer in the range [1, target] is obtainable.
//
//A subsequence of an array is a new non-empty array that is formed from the original array by deleting some (possibly none) of the elements without disturbing the relative positions of the remaining elements.

class Solution {
public:
    void recurse(vector<int>A, int sum, vector<bool> &done, int i)
    {
        if(i<A.size())
        {
            int temp = sum;
            sum+=A[i];
            if(sum<done.size()) done[sum]=true;

            recurse(A,sum,done,i+1);
            recurse(A,temp,done,i+1);
        }
    }
    void updatedone(int x, int target, vector<bool> &done)
    {
        for(int i=target-x;i>=0;i--)
        {
            if(done[i]) done[i+x]=true;
        }
    }




    void printdone(vector<bool>done)
    {
        for(int i=1;i<done.size();i++)
            if(done[i]) cout<<" "<<i;

        cout<<endl;
    }
    int minimumAddedCoins(vector<int>& A, int target) {

        sort(A.begin(),A.end());

        vector<bool>done(target+1, false);
        int sum=0;
        //recurse(A,sum,done,0);
        //printdone(done);
        for(int i=0;i<A.size();i++)
        {
            updatedone(A[i], target, done);
            done[A[i]]=true;
        }

        //printdone(done);

        int res=0;

        for(int i=1;i<=target;i++)
        {
            if(done[i]!=true)
            {
                res++;

                cout<<i<<endl;
                updatedone(i,target,done);
                done[i]=true;
                //printdone(done);
            }
        }
        return res;
    }
};