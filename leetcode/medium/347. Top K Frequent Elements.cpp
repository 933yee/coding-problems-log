class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<pair<int, int>> v;
        vector<int> ret;
        for (int& i : nums) mp[i]++;
        for (auto i : mp) v.push_back({i.first, i.second});
        sort(v.begin(), v.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.second > b.second;
             });
        for (int i = 0; i < k; i++) ret.push_back(v[i].first);
        return ret;
    }
};