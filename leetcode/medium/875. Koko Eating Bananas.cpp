class Solution {
    int isvalid(int k, vector<int>& piles, int h) {
        long long time = 0;
        for (int& i : piles) {
            time += i / k;
            if (i % k) ++time;
        }
        return time <= h;
    }

   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = INT_MIN, ret;
        for (int& i : piles)
            r = max(r, i);

        while (l <= r) {
            int m = (l + r) / 2;
            if (isvalid(m, piles, h)) {
                ret = m;
                r = m - 1;
            } else
                l = m + 1;
        }
        return ret;
    }
};