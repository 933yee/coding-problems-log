class Solution {
   public:
    bool isAnagram(string s, string t) {
        int cnt1[26] = {};
        int cnt2[26] = {};
        bool flag = true;
        for (auto& c : s) cnt1[c - 'a']++;
        for (auto& c : t) cnt2[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};