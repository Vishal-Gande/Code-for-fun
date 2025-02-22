// lc 1029
// A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

// Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.



// Example 1:

// Input: costs = [[10,20],[30,200],[400,50],[30,20]]
// Output: 110
// Explanation:
// The first person goes to city A for a cost of 10.
// The second person goes to city A for a cost of 30.
// The third person goes to city B for a cost of 50.
// The fourth person goes to city B for a cost of 20.

// The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
// Example 2:

// Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
// Output: 1859
// Example 3:

// Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
// Output: 3086


// Constraints:

// 2 * n == costs.length
// 2 <= costs.length <= 100
// costs.length is even.
// 1 <= aCosti, bCosti <= 1000



class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

        priority_queue<pair<int,int>>  pq; //
        for(int i=0;i<costs.size();i++)
        {
            int diff = abs(costs[i][0]-costs[i][1]);
            pq.push(make_pair(diff,i));
        }
        int n=costs.size()/2;
        vector<int>mark(2*n, 0);
        int a_cnt=0, b_cnt=0;
        int res=0;
        while(a_cnt<n && b_cnt<n)
        {
            pair p = pq.top();
            pq.pop();
            int index = p.second;
            cout<<index<<endl;
            mark[index]=1;

            int mini = min(costs[index][0], costs[index][1]);
            res += mini;
            if(mini == costs[index][0]) a_cnt++;
            else b_cnt++;
        }

        if(a_cnt == n)
        {
            for(int i=0;i<2*n;i++)
            {
                if(mark[i]==0)
                    res+= costs[i][1];
            }
        }
        else
        {
            for(int i=0;i<2*n;i++)
            {
                if(mark[i]==0)
                    res+= costs[i][0];
            }
        }

        return res;
    }
};