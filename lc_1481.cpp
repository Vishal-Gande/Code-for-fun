// LC 1481

// Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.



// Example 1:

// Input: arr = [5,5,4], k = 1
// Output: 1
// Explanation: Remove the single 4, only 5 is left.
// Example 2:
// Input: arr = [4,3,1,1,3,3,2], k = 3
// Output: 2
// Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        unordered_map<int,int>mp;

        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }

        int uniq = mp.size();

        map<int,int>mp_freq;

        for(auto it=mp.begin();it!=mp.end();it++)
        {
            mp_freq[it->second]++;
        }

        for(auto it=mp_freq.begin();it!=mp_freq.end() && k;it++)
        {
            int freq = it->first;
            int freq_freq = it->second;

            int reduce = k/freq;

            if(freq_freq < reduce)
            {
                reduce = freq_freq;
            }

            uniq -= reduce;
            k = k - reduce * freq ;

        }

        return uniq;
    }
};