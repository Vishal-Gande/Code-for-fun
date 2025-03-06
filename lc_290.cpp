// lc 290
// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

// Each letter in pattern maps to exactly one unique word in s.
// Each unique word in s maps to exactly one letter in pattern.
// No two letters map to the same word, and no two words map to the same letter.



class Solution {
public:
    bool wordPattern(string p, string s) {

        s = s+" " ; // to aid in capturing last word

    map<char,string> mp1; //char, and it's positions
    int n1 = p.length(), n2 = s.length();

    for(int i=0;i<n1;i++)
    {
        char x = p[i];

        if(mp1.find(x)==mp1.end())
        {
            string temp = to_string(i);
            mp1.insert(make_pair(x,temp));
        }
        else mp1[x] += to_string(i);
    }

    map<string,string>mp2; // words and their position as string
    vector<string>words;
    string temp;
    int count = 0;
    for(int i=0;i<n2;i++)
    {
        char x = s[i];

        if(x!=' ')
        {
            temp += x;
        }
        else
        {
            if(mp2.find(temp)==mp2.end())
            {
                mp2.insert(make_pair(temp,to_string(count)));
            }
            else mp2[temp] += to_string(count);

            count++;
            //cout<<mp2[temp]<<endl;
            words.push_back(temp);
            //cout<<temp<<endl;
            temp = "";
        }

    }


    //cout<<"words size: "<<words.size()<<endl;
    if(p.size() != words.size()) return false;


    for(int i=0;i<n1;i++)
    {
        char x = p[i];
        string y = words[i];



        //cout<<mp1[x]<<" "<<mp2[y]<<endl;
        if(mp1[x] != mp2[y]) return false;
    }

    return true;

    }
};