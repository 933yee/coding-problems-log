class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n;) {
            int target = 0 - nums[i];
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum > target)
                    r--;
                else if (sum < target)
                    l++;
                else {
                    ret.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    l++, r--;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                }
            }
            i++;
            while (i < n && nums[i] == nums[i - 1]) i++;
        }
        return ret;
    }
};