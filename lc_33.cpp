// lc_33
// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.



// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4



class Solution {
public:


    int search(vector<int>& nums, int target) {


        int n=nums.size();
        int last_ele = nums[n-1];
        int left = 0;
        int right = n-1;
        int pivot_index;
        //finding the pivot
        if(nums[0]>nums[n-1])
        {
            while(right-left>1) // iterate until they touch
            {
                int index = (left+right)/2;
                int x = nums[index];
                if(x>last_ele)
                {
                    left = index;
                }
                else
                {
                    right = index;
                }
                //cout<<x<<endl;
                //cout<<left<<" "<<right<<endl;
            }

            if(nums[left]>nums[right]) pivot_index = right;
            else pivot_index = left;

            int index1 = lower_bound(nums.begin(), nums.begin()+pivot_index, target) - nums.begin(); //(inclus,exclus)
            int index2 = lower_bound(nums.begin()+pivot_index, nums.end(), target) - nums.begin();

            if(index1<n && nums[index1]==target) return index1;
            if(index2<n && nums[index2]==target) return index2;
        }
        // no rotation case
        else
        {
            int index1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            if(index1<n && nums[index1]==target) return index1;
        }

        return -1;

    }
};