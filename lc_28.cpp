//lc_28
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
class Solution {
public:
    int strStr(string haystack, string needle) {

        int n1 = haystack.size();
        int n2 = needle.size();

        for(int i=0;i<n1;i++)
        {
            for(int j=i,k=0;j<n1 && k<n2;j++,k++)
            {
                if(haystack[j]!=needle[k])
                    break;

                if(k==n2-1) return i;
            }
        }

        return -1;

    }
};