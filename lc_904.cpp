
//lc 904
// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.
class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        map<int,int>mp; //fruit type, last seen index
        int prev_f = fruits[0];
        mp.insert(make_pair(fruits[0],0));
        int counter = 1;
        int res = 1;

        for(int i=1;i<fruits.size();i++)
        {
            int x = fruits[i];

            if(mp.find(x)==mp.end() && mp.size()==2)
            {
                //cout<<"yes"<<endl;
                auto it = mp.begin();
                if(it->first == prev_f)
                {
                    it++;
                }

                int rem_f = it->first;
                int last_index = it->second;
                cout<<rem_f<<" "<<last_index<<endl;
                mp.insert(make_pair(x,i));
                counter = i-last_index;
                mp.erase(rem_f);
            }
            else
            {
                //cout<<"no"<<endl;
                mp[x]=i;
                counter++;

            }
            prev_f = x;
            //cout<<counter<<endl;

            if(counter>res) res = counter;
        }

        return res;

    }
}