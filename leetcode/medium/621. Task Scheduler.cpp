// greedy (AC)
// https://leetcode.cn/problems/task-scheduler/solutions/196302/tong-zi-by-popopop/

class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {};
        for (char& c : tasks)
            cnt[c - 'A']++;
        int mx = 0, num = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                if (cnt[i] > mx) {
                    mx = cnt[i];
                    num = 1;
                } else if (cnt[i] == mx) {
                    num++;
                }
            }
        }
        int len = tasks.size();
        return max(len, (mx - 1) * (n + 1) + num);
    }
};