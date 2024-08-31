//QSN: Neetcode 150 - Longest Substring Without Duplicates 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.length()==0) return 0;
        //set<char>mp;
        map<char,int>mp;
        int maxi=-1, initial = 0;
        char x;
        for(int i=0;i<s.length();i++)
        {
            x = s[i];
            if(mp.find(x)!= mp.end() && mp[x]>=initial)
            {
                initial = mp[x]+1;
            }
            if(i-initial+1>maxi) maxi=i-initial+1;
            mp[x]=i;
        }
        return maxi;
        
    }
};

