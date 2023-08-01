// sliding window (AC)
// 慢慢往右邊拓展，如果當前window大小減去最多數的字母超過k值，代表當前的window不能達成條件，
// 且由於左指針是一個一個往又拓展的，超過k值時只要把左指針往右一個就好。

class Solution {
   public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.size(), mx = 0, cnt[26] = {};
        while (r < n) {
            mx = max(mx, ++cnt[s[r++] - 'A']);
            if (r - l - mx > k) --cnt[s[l++] - 'A'];
        }
        return n - l;
    }
};