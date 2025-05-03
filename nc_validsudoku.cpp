vector<vector<char>> B;

class Solution {
public:
    bool checkgrid(int x, int y)
    {
        set<int>mp;
        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
            {
                if(B[i][j] != '.')
                {
                    //cout<<"grid"<<" "<<i<<j<<endl;
                    int k = B[i][j]-'0';

                    if(k>9 || k<1 || mp.find(k)!=mp.end()) return false;
                    else mp.insert(k);
                }
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& b) {

        B.clear();
        B = b;
        //cout<<B[0][0];
        //check rows

        for(int i=0;i<9;i++)
        {
            set<int>mp;
            for(int j=0;j<9;j++)
            {
                char c = b[i][j];
                if(c != '.')
                {
                    int x = b[i][j]-'0';

                    if(x>9 || x<1 || mp.find(x)!=mp.end()) return false;
                    else mp.insert(x);
                }


            }
        }

        //cout<<"hi";
        //check columns

        for(int j=0;j<9;j++)
        {
            set<int>mp;
            for(int i=0;i<9;i++)
            {
                char c = b[i][j];
                if(c != '.')
                {
                    int x = b[i][j]-'0';

                    if(x>9 || x<1 || mp.find(x)!=mp.end()) return false;
                    else mp.insert(x);
                }


            }
        }

        //return false;
        //cout<<"yes";
        if(checkgrid(0,0) == false) return false;
        if(checkgrid(0,3) == false) return false;

         //cout<< "yes2";
        if(checkgrid(0,6) == false) return false;
        if(checkgrid(3,0) == false) return false;
        if(checkgrid(3,3) == false) return false;



        if(checkgrid(3,6) == false) return false;
        if(checkgrid(6,0) == false) return false;
        if(checkgrid(6,3) == false) return false;
        if(checkgrid(6,6) == false) return false;


        return true;

    }
};
