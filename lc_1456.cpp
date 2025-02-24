// //lc_1456

// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.



// Example 1:

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.
// Example 2:

// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.
// Example 3:

// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.

class Solution {
public:
    int maxVowels(string s, int k) {

        int res = 0;
        int n=s.size();
        vector<int>count;
        int counter = 0;
        count.push_back(0);
        for(int i=0;i<n;i++)
        {
            char x = s[i];
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u')
            {
                counter++;
            }
            count.push_back(counter);
        }

        for(int i=0;i+k<=n;i++)
        {
            int vowels = count[i+k] - count[i];
            if(vowels > res ) res = vowels;
        }

        return res;

    }
};