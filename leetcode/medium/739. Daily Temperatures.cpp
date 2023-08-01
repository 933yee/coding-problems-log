// 單調棧 (AC)

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ret(n, 0);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first < temperatures[i]) {
                ret[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push(make_pair(temperatures[i], i));
        }
        return ret;
    }
};