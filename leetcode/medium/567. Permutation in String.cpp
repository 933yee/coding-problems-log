class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int cnt1[26] = {}, cnt2[26] = {};
        int n1 = s1.size(), n2 = s2.size();
        int l = 0, r = n1;

        if (n2 < n1) return false;
        for (int i = 0; i < n1; i++) {
            ++cnt1[s1[i] - 'a'];
            ++cnt2[s2[i] - 'a'];
        }
        while (r <= n2) {
            bool same = true;
            for (int i = 0; i < 26; i++) {
                if (cnt1[i] != cnt2[i]) {
                    same = false;
                    break;
                }
            }
            if (same) return true;
            if (r == n2) break;
            --cnt2[s2[l++] - 'a'];
            ++cnt2[s2[r++] - 'a'];
        }
        return false;
    }
};