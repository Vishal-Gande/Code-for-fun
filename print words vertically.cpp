
// LC 1324 - Print words vertically
class Solution {
public:
    vector<string> printVertically(string s) {

        vector<string>S;
        vector<string> res;
        string temp;
        int max = 0;
        int counter = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                temp+= s[i];
                counter++;
                if(counter>max){
                    max = counter;
                }

            }
            else
            {
                S.push_back(temp);
                temp="";
                if(counter>max){
                    max = counter;
                }
                counter = 0;
            }
        }

        S.push_back(temp); // adding last word

        //cout<<"maxi is"<<max;
        for(int i=0;i<max;i++)
        {

            string x;
            int last_index = 0;
            for(int j=0;j<S.size();j++)
            {
                if(i<S[j].length())
                {
                    x+=S[j][i];
                    last_index = j;
                }
                else x+=" ";
            }
            string temp(x,0,last_index+1); // for removing trailing spaces
            res.push_back(temp);
            x="";
        }

        return res;



    }
};
