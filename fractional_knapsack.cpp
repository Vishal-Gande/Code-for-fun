
// // fractinal knapsack

// Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.

// Also given an integer C which represents knapsack capacity.

// Find out the maximum total value that we can fit in the knapsack. If the maximum total value is ans, then return ⌊ans × 100⌋ , i.e., floor of (ans × 100).

// NOTE:

// You can break an item for maximizing the total value of the knapsack

int Solution::solve(vector<int> &A, vector<int> &B, int C) {

    priority_queue<pair<double, int>> pq; // val/weight, index
    int n = A.size();

    for(int i=0;i<n;i++)
    {
        double x = (double)(A[i]*100)/(double)B[i];

        pq.push(make_pair(x,i));
    }
    double total_value=0;

    while(C && pq.size())
    {
        pair<double, int> p = pq.top();
        int index = p.second;
        int w = B[index];
        double filled = 0;
        if(C>=w)
        {
            filled = w;
        }
        else
        {
            filled = C;
        }

        C = C- filled;

        total_value += filled * p.first;
        pq.pop();
        //cout<<total_value<<endl;
    }
    //total_value = total_value*100;

    return (int)total_value;




}
