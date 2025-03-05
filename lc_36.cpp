// lc 36
// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.

bool checkrow(int row, vector<vector<char>>& board)
{
    set<char>mp;
    for(int j=0;j<9;j++)
    {
        char x = board[row][j];
        if(x!='.')
        {

            if(mp.find(x)!=mp.end())
            {
                cout<<"row "<<row<<" "<<x<<endl;
                return false;
            }
            else    mp.insert(x);
        }
    }
    return true;
}

bool checkcol(int col, vector<vector<char>>& board)
{
    set<char>mp;
    for(int i=0;i<9;i++)
    {
        char x = board[i][col];
        if(x!='.'){
            if(mp.find(x)!=mp.end())
            {
                cout<<"col "<<col<<" "<<x<<endl;
                return false;
            }
            else    mp.insert(x);
        }
    }
    return true;
}

void checksquare(int row, int col, vector<vector<char>>& board, bool &flag)
{
    set<char>mp;

    for(int i=row ; i<row+3;i++)
    {
        for(int j=col; j<col+3; j++)
        {
            char x = board[i][j];
            if(x!='.'){
                if(mp.find(x)!=mp.end())
                {
                    cout<<"square "<<row <<"and "<<col<<" "<<x<<endl;
                    flag=false;
                }
                else    mp.insert(x);
            }
        }
    }
    //return true;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;i++)
        {
            bool flag = checkrow(i,board);
            if(flag==false) return false;
        }

        for(int j=0;j<9;j++)
        {
            bool flag = checkcol(j,board);
            if(flag==false) return false;
        }

        bool flag = true;

        checksquare(0,0,board,flag);
        checksquare(0,3,board,flag);
        checksquare(0,6,board,flag);

        checksquare(3,0,board,flag);
        checksquare(3,3,board,flag);
        checksquare(3,6,board,flag);

        checksquare(6,0,board,flag);
        checksquare(6,3,board,flag);
        checksquare(6,6,board,flag);

        return flag;

    }
};