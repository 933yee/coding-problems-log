class Solution {
   public:
    struct cmp {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[0] > b[0];
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ret;
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for (auto& v : points) {
            pq.push({v[0] * v[0] + v[1] * v[1], v[0], v[1]});
        }
        while (k--) {
            ret.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }
        return ret;
    }
};