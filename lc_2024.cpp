// lc 2024
// A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

// You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

// Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
// Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

class Solution {
public:
    int maxConsecutiveAnswers(string A, int k) {

        int maxi = 0;
        int n = A.size();
        vector<int>prefix_T;
        vector<int>prefix_F;
        int sum=0, sumf=0;
        prefix_T.push_back(0);
        prefix_F.push_back(0);

        for(int i=0;i<n;i++)
        {
            if(A[i]=='T') sum++;
            else sumf++;

            prefix_T.push_back(sum);
            prefix_F.push_back(sumf);
        }

        int left = 0, right = 0;

        while(right<n)
        {

            if( (right-left+1) - (prefix_T[right+1]-prefix_T[left]) <= k)
            {
                maxi = max(maxi, right-left+1);
                right++;
            }

            else
            {
                //maxi = max(maxi, right-left);
                cout<<maxi<<endl;
                left++;
            }
        }

        left = 0;
        right = 0;
        while(right<n)
        {
            if( (right-left+1) - (prefix_F[right+1]-prefix_F[left]) <= k)
            {
                maxi = max(maxi, right-left+1);
                right++;
            }

            else
            {
                //maxi = max(maxi, right-left);
                left++;
            }

        }



        return maxi;

    }
};