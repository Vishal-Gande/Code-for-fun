//lc 2824
// Given a 0-indexed integer array nums of length n and an integer target, return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            int x = nums[i];
            int y = target - x;

            int index = lower_bound(nums.begin()+i+1,nums.end(),y) - nums.begin();
            //cout<<x<<" "<<y<<" "<<index<<endl;
            if(index<=n && index>i+1)
                res = res + index-i-1;

            //cout<<res<<endl;
        }

        return res;
    }
};