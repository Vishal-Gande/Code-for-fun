class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<vector<int>, int > mp; //stores str, index in res

        vector<vector<string>> res;
        string s;
        char x;
        for(int i=0;i<strs.size();i++)
        {
            s=strs[i];  
            vector<int>count(26,0);
            for(int j=0; j<s.length(); j++)
            {
                x=s[j];
                count[x-'a']++;
            }

            if(mp.find(count)==mp.end())
            {
                vector<string>dummy;
                dummy.push_back(s);
                res.push_back(dummy);
                mp.insert(make_pair(count,res.size()-1)); 
            }
            else{

                int index = mp[count];
                res[index].push_back(s);
            }

        }

        return res;
        
    }
};
