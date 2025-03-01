// gfg minimum platforms
// You are given the arrival times arr[] and departure times dep[] of all trains that arrive at a railway station on the same day. Your task is to determine the minimum number of platforms required at the station to ensure that no train is kept waiting.

// At any given time, the same platform cannot be used for both the arrival of one train and the departure of another. Therefore, when two trains arrive at the same time, or when one arrives before another departs, additional platforms are required to accommodate both trains.

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(), dep.end());
        int a = 0, d = 0;
        int n1 = arr.size();
        int n2 = dep.size();
        int cur_time = arr[0];
        int  max_platforms = 0;
        int  counter = 0;
        
        while(a<n1)
        {
            //cout<<counter<<endl;
            int x = arr[a];
            int y = dep[d];
            
            if(x<=y) // = cos even if one arrives and another departs at same time, we need to consider arrival first
            {
                counter++;
                max_platforms = max(counter,max_platforms);
                a++;
            }
            else
            {
                counter--;
                d++;
            }
            
        }
        
        return max_platforms;
    }
};