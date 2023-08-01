class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            auto f = mp.find(target - nums[i]);
            if (f != mp.end()) {
                return vector<int>{i, f->second};
            }
            mp.insert({nums[i], i});
        }
        return vector<int>{};
    }
};