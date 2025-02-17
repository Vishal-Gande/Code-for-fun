//lc_1701
//There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:
//
//arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
//timei is the time needed to prepare the order of the ith customer.
//When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.
//
//Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& C) {

        long long int total_wait=0;
        long long int sum = 0;
        long long int cur_time=0;
        int a,t;

        for(int i=0;i<C.size();i++)
        {
            a = C[i][0];
            t = C[i][1];
            if(cur_time <= a)
            {
                cur_time = a + t;
                total_wait = t;
                sum += total_wait;
            }
            else
            {
                total_wait = t+cur_time-a;
                cur_time +=t;
                sum += total_wait;
            }


        }
        double res;

        res = ((double)sum)/C.size();

        return res;


    }
};