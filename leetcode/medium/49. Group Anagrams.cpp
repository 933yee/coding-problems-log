class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string, int> mp;
        for (string& s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            auto f = mp.find(sorted_s);
            if (f == mp.end()) {
                mp.insert({sorted_s, ret.size()});
                ret.push_back(vector<string>{s});
            } else {
                ret[f->second].push_back(s);
            }
        }
        return ret;
    }
};