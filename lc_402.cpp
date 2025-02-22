// lc_402
// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
class Solution {
public:
    string removeKdigits(string s, int k) {

        if (k==0) return s;

        if(s.size()==1) return "0"; // k==0 is already covered, so k=1 here
        stack<int>st;

        for(int i=0;i<s.size();i++)
        {
            int x = s[i] - '0';

            if(st.size() == 0) st.push(x);

            else
            {
                int top = st.top();
                bool flag = true;
                while(st.size() && st.top() > x && k)
                {
                    flag=false;
                    st.pop();
                    k--;

                }
                st.push(x);

            }
        }
        // "112" , k=1, some might still be left
        while(k)
        {
            st.pop();
            k--;
        }

        vector<int>res;

        while(st.size())
        {
            int x = st.top();

            res.push_back(x);
            st.pop();
        }

        string res1;

        bool flag=true;
        for(int i=res.size()-1;i>=0;i--)
        {
            if(flag)
            {
                if(res[i]!=0 )
                {
                    res1 += res[i] + '0';
                    flag = false;
                }

            }
            else res1 += res[i] + '0';
        }

        if(res1.size() == 0) return "0";
        return res1;


    }
};