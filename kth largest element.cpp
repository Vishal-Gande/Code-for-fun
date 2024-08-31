class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int> , greater<int> > pq; //min heap
        int x;

        for(int i=0;i<nums.size();i++)
        {
            x = nums[i];
            if(pq.size()<k) pq.push(x); //keep filling until u reach k elements
            
            else{
                if(x>pq.top()) // always store top k
                {
                    pq.pop();
                    pq.push(x);
                }
            }
        }
        return pq.top();
    }
};
