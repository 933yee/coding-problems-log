class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ret = 0, cheap = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            ret = max(ret, prices[i] - cheap);
            cheap = min(cheap, prices[i]);
        }
        return ret;
    }
};