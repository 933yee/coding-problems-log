class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ret = 0, cnt = 0, l = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.count(s[i]) && mp[s[i]] >= l) {
                cnt = i - mp[s[i]];
                l = mp[s[i]] + 1;
            } else {
                cnt++;
            }
            mp[s[i]] = i;
            ret = max(ret, cnt);
        }
        return ret;
    }
};