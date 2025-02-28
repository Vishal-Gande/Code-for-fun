//lc 12
//integer to roman

class Solution {
public:
    map<string,int>mp;
    string intToRoman(int num) {
        mp.insert(make_pair("M", 1000));
        mp.insert(make_pair("CM", 900));
        mp.insert(make_pair("D", 500));
        mp.insert(make_pair("CD", 400));
        mp.insert(make_pair("C", 100));
        mp.insert(make_pair("XC", 90));
        mp.insert(make_pair("L", 50));
        mp.insert(make_pair("XL", 40));
        mp.insert(make_pair("X", 10));
        mp.insert(make_pair("IX", 9));
        mp.insert(make_pair("V", 5));
        mp.insert(make_pair("IV", 4));
        mp.insert(make_pair("I", 1));

        vector<string> romans{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;
        int index = 0;
        while(num)
        {
            string x = romans[index];
            int count = num/mp[x];

            int k = count;

            while(k)
            {
                res += romans[index];
                k--;
            }
            num = num - count * mp[x];
            index++;
        }

        return res;
    }
};