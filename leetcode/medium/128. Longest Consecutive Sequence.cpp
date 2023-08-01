class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ret = 0;
        for (int& i : nums) {
            int cnt = 1, cur = i;
            auto f = st.find(i);
            if (f != st.end()) {
                st.erase(f);
                int left = cur - 1, right = cur + 1;
                while (st.find(left) != st.end()) {
                    cnt++;
                    st.erase(left--);
                }
                while (st.find(right) != st.end()) {
                    cnt++;
                    st.erase(right++);
                }
                ret = max(ret, cnt);
            }
        }
        return ret;
    }
};