//LC 1768

//You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
//
//Return the merged string.

class Solution {
public:
    string mergeAlternately(string w1, string w2) {

        string res;

        while(1)
        {
            for(int i=0,j=0;i<w1.size() || j<w2.size();i++,j++)
            {
                if(i<w1.size()) res+= w1[i];
                if(j<w2.size()) res+= w2[j];
            }
            break;
        }

        return res;

    }
};