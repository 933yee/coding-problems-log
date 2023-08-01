class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> l{1}, r{1}, ret;

        for (int i = 0; i < n - 1; i++)
            l.push_back(l[i] * nums[i]);
        for (int i = n - 1; i > 0; i--)
            r.push_back(r[n - 1 - i] * nums[i]);
        for (int i = 0; i < n; i++)
            ret.push_back(l[i] * r[n - 1 - i]);

        return ret;
    }
};