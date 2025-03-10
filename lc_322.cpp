// lc 322

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {


        vector<int>steps(amount+1, -1);
        steps[0]=0;

        for(int i=1;i<=amount;i++)
        {
            bool flag=true;
             for(int j=0;j<coins.size();j++)
             {
                int coin = coins[j];

                if(i-coin >= 0 && steps[i-coin]!= -1)
                {
                    if(flag==true){
                        steps[i] = steps[i-coin]+1;
                        flag=false;

                    }

                    else steps[i] = min(steps[i],steps[i-coin]+1);
                }
             }
             cout<<steps[i]<<" ";
        }

        return steps[amount];



    }
};