// lc_2215

// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

// answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
// answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
// Note that the integers in the lists may be returned in any order.



class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        set<int>st1;
        set<int>st2;

        for(int i=0;i<n1;i++)
        {
            st1.insert(nums1[i]);
        }

        for(int i=0;i<n2;i++)
        {
            st2.insert(nums2[i]);
        }

        vector<vector<int>>res;
        vector<int>temp1;
        for(auto it=st1.begin();it!=st1.end();it++)
        {
            int x = *it;

            if(st2.find(x)==st2.end())
            {
                temp1.push_back(x);
            }
        }

        res.push_back(temp1);
        vector<int>temp2;

        for(auto it=st2.begin();it!=st2.end();it++)
        {
            int x = *it;

            if(st1.find(x)==st1.end())
            {
                temp2.push_back(x);
            }
        }

        res.push_back(temp2);


        return res;


    }
};