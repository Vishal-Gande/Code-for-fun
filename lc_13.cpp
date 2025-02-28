// // lc_ 13

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

class Solution {
public:
    map<char,int>mp;

    int romanToInt(string A) {
        mp.insert(make_pair('M',1000));
        mp.insert(make_pair('D',500));
        mp.insert(make_pair('C',100));
        mp.insert(make_pair('L',50));
        mp.insert(make_pair('X',10));
        mp.insert(make_pair('V',5));
        mp.insert(make_pair('I',1));
        int res = 0;
        int n=A.size();
        char x,y;
        for(int i=0;i<n-1;i++)
        {
            x = A[i];
            y = A[i+1];
            if(mp[x]>=mp[y])
            {
                res += mp[x];
            }
            else res = res - mp[x];

            //cout<<res<<endl;
        }

        res = res + mp[A[n-1]]; // last element
        //cout<<"yes"<<mp[]<<endl;
        return res;

    }
};