// LC_2336

// You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

// Implement the SmallestInfiniteSet class:

// SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
// int popSmallest() Removes and returns the smallest integer contained in the infinite set.
// void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
class SmallestInfiniteSet {
public:

    priority_queue<int, vector<int> , greater<int> > pq;
    unordered_map<int,int>mp; //freq;

    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
        {
            pq.push(i);
            mp[i]++;
        }
    }

    int popSmallest() {

        int x = pq.top();
        pq.pop();
        mp[x]--;
        return x;
    }

    void addBack(int num) {

        if(mp[num]<1){
            mp[num]++;
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */