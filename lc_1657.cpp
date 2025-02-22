//lc_1657

// Two strings are considered close if you can attain one from the other using the following operations:

// Operation 1: Swap any two existing characters.
// For example, abcde -> aecdb
// Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
// For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
// You can use the operations on either string as many times as necessary.

// Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

class Solution {
public:
    bool closeStrings(string w1, string w2) {

        map<char,int>mp1;
        map<char,int>mp2;


        for(int i=0;i<w1.size();i++)
        {
            char x = w1[i];
            mp1[x]++;
        }

        for(int i=0;i<w2.size();i++)
        {
            char x = w2[i];
            mp2[x]++;
        }
        if(mp1.size() != mp2.size()) return false;

        // chars are diff case
        for(auto it1=mp1.begin(), it2=mp2.begin() ;it1!=mp1.end();it1++,it2++)
        {
            if(it1->first != it2->first) return false;
        }

        vector<int>f1;
        vector<int>f2;


        for(auto it=mp1.begin();it!=mp1.end();it++)
        {
            f1.push_back(it->second);
        }

        for(auto it=mp2.begin();it!=mp2.end();it++)
        {
            f2.push_back(it->second);
        }

        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());

    if(f1.size()!=f2.size()) return false;

    for(int i=0;i<f1.size();i++)
    {
        if(f1[i]!=f2[i]) return false;
    }

    return true;



    }
};