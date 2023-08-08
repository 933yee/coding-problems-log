class KthLargest {
   public:
    struct cmp {
        bool operator()(int a, int b) {
            return a > b;
        }
    };
    priority_queue<int, vector<int>, cmp> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int& i : nums)
            pq.push(i);
        while (pq.size() > k)
            pq.pop();
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};
