// lc 1668
// For a string sequence, a string word is k-repeating if word concatenated k times is a substring of sequence. The word's maximum k-repeating value is the highest value k where word is k-repeating in sequence. If word is not a substring of sequence, word's maximum k-repeating value is 0.

// Given strings sequence and word, return the maximum k-repeating value of word in sequence.



class Solution {
public:
    int maxRepeating(string seq, string w) {

        int n = seq.length();
        int m = w.length();
        int j=0;
        int counter=0, maxi=0;

        for(int i=0;i<seq.size();i++)
        {
            int counter=0;
            j=0;
            int temp = i;
            if(seq[i]==w[j])
            {

                while(i<n && j<m)
                {
                    if(seq[i]==w[j])
                    {
                        if(j==m-1){
                            counter++;
                            maxi = max(counter,maxi);
                            j=-1; // as j++ will be done, but we want j=0
                        }

                        i++;
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }

            }
            i = temp;
        }

        return maxi;

    }
};