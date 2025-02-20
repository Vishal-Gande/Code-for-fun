// lc 2390
// ou are given a string s, which contains stars *.

// In one operation, you can:

// Choose a star in s.
// Remove the closest non-star character to its left, as well as remove the star itself.
// Return the string after all stars have been removed.

// Note:

// The input will be generated such that the operation is always possible.
// It can be shown that the resulting string will always be unique.

class Solution {
public:
    string removeStars(string s) {

        stack<char>st;

        for(int i=0;i<s.size();i++)
        {
            char x = s[i];

            if(x!='*')
            {
                st.push(x);
            }
            else if(st.size())
            {
                st.pop();
            }
        }
        string res;
        while(st.size())
        {
            res += st.top();
            st.pop();
        }

        string res1;

        for(int i=res.size()-1;i>=0;i--)
        {
            res1 += res[i];
        }

        return res1;
    }
};