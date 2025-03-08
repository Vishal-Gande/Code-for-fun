// lc 1947
// There is a survey that consists of n questions where each question's answer is either 0 (no) or 1 (yes).

// The survey was given to m students numbered from 0 to m - 1 and m mentors numbered from 0 to m - 1. The answers of the students are represented by a 2D integer array students where students[i] is an integer array that contains the answers of the ith student (0-indexed). The answers of the mentors are represented by a 2D integer array mentors where mentors[j] is an integer array that contains the answers of the jth mentor (0-indexed).

// Each student will be assigned to one mentor, and each mentor will have one student assigned to them. The compatibility score of a student-mentor pair is the number of answers that are the same for both the student and the mentor.

class Solution {
public:
    void backtrack(vector<vector<int>> &comp, int &max_score, int score, set<int>cols, int row)
    {
        if(row<comp.size() && cols.size()<comp.size())
        {
            for(int j=0;j<comp.size();j++)
            {
                if(cols.find(j)==cols.end())
                {
                    cols.insert(j);
                    score += comp[row][j];
                    backtrack(comp, max_score, score, cols, row+1);
                    cols.erase(j);
                    score -= comp[row][j];
                }

            }
        }
        max_score = max(max_score, score);
    }
    int maxCompatibilitySum(vector<vector<int>>& S, vector<vector<int>>& M) {

        int m = S.size();

        vector<vector<int>> comp(m);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                int score=0;
                for(int k=0;k<S[0].size();k++)
                {
                    if(S[i][k]==M[j][k])
                        score++;
                }
                comp[i].push_back(score);
            }

        }
        int max_score=0, score=0;
        set<int>cols; //processed mentors
        backtrack(comp, max_score, score, cols, 0);

        return max_score;
    }
};