// LC_122
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit=0, buyp, sellp, prev=prices[0], p;
        bool bought = false;

        int n = prices.size();
        for(int i=1;i<prices.size();i++)
        {
            p = prices[i];

            if(p>prev && bought==false)
            {
                bought = true;
                buyp = prev;
                cout<<"bought at : "<<buyp<<endl;
            }

            if(p<prev && bought==true)
            {
                profit += prev - buyp;
                cout<<"sold at : "<<prev<<endl;

                bought = false;
            }
            prev = p;
        }
        // 1,2,3 case
        if(bought)
        {
            profit += prices[n-1]-buyp;
        }

        return profit;

    }
};