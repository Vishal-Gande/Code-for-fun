//LC_2529

// Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

// In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
// Note that 0 is neither positive nor negative.



// Example 1:

// Input: nums = [-2,-1,-1,1,2,3]
// Output: 3
// Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.

class Solution {
public:
    int maximumCount(vector<int>& A) {

        int n = A.size();
        int pos_index = lower_bound(A.begin(),A.end(),1) - A.begin();

        int positives = n-pos_index;

        int neg_index = lower_bound(A.begin(),A.end(),0) - A.begin();
        int negatives = neg_index;

        cout<<positives<<" "<<negatives<<endl;

        return max(positives,negatives);

    }
};