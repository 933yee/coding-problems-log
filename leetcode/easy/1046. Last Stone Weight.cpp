class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (true) {
            if (pq.empty())
                return 0;
            else if (pq.size() == 1)
                return pq.top();
            else {
                int a = pq.top();
                pq.pop();
                int b = pq.top();
                pq.pop();
                if (a != b)
                    pq.push(a - b);
            }
        }
        return -1;
    }
};