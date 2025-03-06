// lc 205

// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char,string>mp1; //char and it's index appended as string
        unordered_map<char,string>mp2;

        int n=s.length();
        if(t.length() != n) return false;

        for(int i=0;i<n;i++)
        {
            char x = s[i];
            char y = t[i];

            if(mp1.find(x)==mp1.end())
            {
                string temp = to_string(i);
                mp1.insert(make_pair(x,temp));
            }
            else mp1[x] += to_string(i);

            if(mp2.find(y)==mp2.end())
            {
                string temp = to_string(i);
                mp2.insert(make_pair(y,temp));
            }
            else mp2[y] += to_string(i);

        }

        //cout<<"hello";
        //cout<<mp1['g']<<"hey";

        for(int i=0;i<n;i++)
        {
            char x = s[i];
            char y = t[i];

            string a = mp1[x];
            string b = mp2[y];

            //cout<<a<<" "<<b<<endl;

            if(a != b ) return false;
        }

        return true;

    }
};