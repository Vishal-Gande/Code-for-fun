// lc 71

//You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

class Solution {
public:
    string simplifyPath(string path) {

        int n=path.length();
        string s="/";
        char prev = path[0];

        // removes extra slashes
        for(int i=1;i<n;i++)
        {
            char x = path[i];
            if(!(x=='/' && x==prev))
            {
                s += x;
            }
            prev = x;
        }
        cout<<s<<endl;
        n = s.length();
        vector<string>W;
        string temp;
        for(int i=1;i<n;i++)
        {
            char x = s[i];
            if(x != '/')
                temp += x;
            else
            {
                W.push_back(temp);
                cout<<temp<<" ";
                temp="";
            }
        }
        if(temp!="" && temp != "/" )
            W.push_back(temp);

        cout<<endl;


        string res = "";
        stack <string> st;
        for(int i=0;i<W.size();i++)
        {
            string x = W[i];
            if (x == ".")
            {


                continue;
            }
            if(x == "..")
            {

                if(st.size())
                {
                    st.pop();

                }
                continue;
            }

            // word case

            st.push(x);
        }

        vector<string>helper;
        while(st.size())
        {
            string x = st.top();
            helper.push_back(x);
            st.pop();
        }

        n = helper.size();
        for(int i=n-1;i>=0;i--)
        {
            if(n!=0)
            {
                res += "/";
            }
            res += helper[i];



            cout<<res<<endl;
        }

        if(res=="" && path.size()) // case /../
            return "/";

        return res;






    }
};