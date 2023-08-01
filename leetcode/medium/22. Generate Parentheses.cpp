// 為了檢查字串是否符合括號格式，可以利用L去計算左括號的個數，遇到右括號就消掉，且如果L < 0，
// 代表右括號在左括號的左邊，可以直接忽略，因此當 L == 0 時，必定是符合的。

class Solution {
    vector<string> ret;
    string cur;

   public:
    void dfs(int cnt, int target, int L) {
        if (L < 0) return;
        if (cnt == target) {
            if (L == 0)
                ret.push_back(cur);
            return;
        }
        cur.push_back('(');
        dfs(cnt + 1, target, L + 1);
        cur.pop_back();

        cur.push_back(')');
        ;
        dfs(cnt + 1, target, L - 1);
        cur.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        dfs(0, n * 2, 0);
        return ret;
    }
};