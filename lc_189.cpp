
// lc 189

// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        k = k%n;
        if(k==0) return ;
        int rotated=0;
        int curr_index = 0;
        int start_index = 0;
        //set<int> done;
        //done.insert(0);
        int curr_num = nums[curr_index];

        while(rotated<n)
        {
            int req_index = curr_index+k;

            if(req_index>=n)
            {
                req_index = k - (n-1-curr_index) - 1;
            }

            int temp = nums[req_index];
            nums[req_index] = curr_num;
            curr_index = req_index;
            curr_num = temp;
            rotated++;
            if(curr_index == start_index)
            {
                start_index++;
                curr_index = start_index;
                curr_num = nums[curr_index];
            }
        }
    }

};