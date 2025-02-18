//lc 950 reveal cards in inc order
// You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].

// You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

// You will do the following steps repeatedly until all cards are revealed:

// Take the top card of the deck, reveal it, and take it out of the deck.
// If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
// If there are still unrevealed cards, go back to step 1. Otherwise, stop.
// Return an ordering of the deck that would reveal the cards in increasing order.

// Note that the first entry in the answer is considered to be the top of the deck.

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        int n = deck.size();
        vector<int>res(n,0);

        sort(deck.begin(),deck.end());
        res[0]=deck[0];
        int index = 1;
        for(int i=1;i<n;i++)
        {
            int x = deck[i];

            bool flag = false;
            bool flag_while=true;
            while(flag_while)
            {
                if(res[index]==0){

                    if(flag==false)
                    {
                        flag=true;
                    }
                    else{
                        res[index] = x;
                        flag_while=false;
                        //cout<<index<<x<<endl;
                    }
                }
                index++;
                if(index==n) index = 0;
            }
        }

        return res;

    }
};