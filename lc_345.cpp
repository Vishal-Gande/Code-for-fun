//lc_345

// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.



// Example 1:

// Input: s = "IceCreAm"

// Output: "AceCreIm"

// Explanation:

// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".
class Solution {
public:
    string reverseVowels(string s) {

        int n = s.size();
        string v ;

        for(int i=0;i<n;i++)
        {
            char x = s[i];

            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U')
            {
                v += x;
            }
        }

        int n2 = v.size();
        n2--;
        for(int i=0;i<n;i++)
        {
            char x = s[i];
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U')
            {
                s[i]=v[n2];
                n2--;
            }
        }

        return s;

    }
};