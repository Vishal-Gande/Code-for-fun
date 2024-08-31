class Solution {
public:
    bool isValid(string s) {

        stack<char>st;
        char x,y;

        for(int i=0;i<s.length();i++)
        {
            x=s[i];
            if(x == '(' || x == '{' || x == '[')
            st.push(x);

            else
            {
                if(st.size()==0) return false; // eg []]
                y=st.top();

    
                if((x==']' && y== '[') || (x=='}' && y== '{') || (x==')' && y== '(')  )
                {
                    st.pop();
                }
                else return false;
            }
        }

    if(st.size()!=0) return false;
    return true;
        
    }
};
