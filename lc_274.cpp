// lc_274
// Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

// According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

class Solution {
public:
    int hIndex(vector<int>& c) {

        int n=c.size();
        sort(c.begin(),c.end(), greater<int>());
        int counter=0, index=0;
        for(int h=c[0];h>=1;h--)
        {
            cout<<h<<endl;
            while(index<n && h==c[index])
            {
                counter++;
                index++;
                //cout<<"yes";
            }
            cout<<h<<endl;
            //iterate all possible values of h-index
            if(counter>=h) return h;
        }
        return 0;
    }
};