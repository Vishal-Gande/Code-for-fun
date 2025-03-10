// lc_151
// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
class Solution {
public:
    string reverseWords(string s) {

        string res;
        priority_queue<int>pq;
        int n = s.size();
        bool flag=true; //first letter
        for(int i=0;i<n;i++)
        {
            char x = s[i];

            if(x!=' ')
            {
                if(flag)
                {
                    flag=false;
                    pq.push(i);
                }
            }
            else
            {
                flag=true;
            }
        }

        while(pq.size())
        {
            int i = pq.top();
            pq.pop();

            string x;
            while(s[i]!= ' ' && i<n)
            {
                x+= s[i];
                i++;
            }
            if(pq.size())
                x+= " ";

            res += x;
        }
        return res;
    }


};