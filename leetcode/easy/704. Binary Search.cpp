// STL (AC)
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        auto f = lower_bound(nums.begin(), nums.end(), target);
        return f != nums.end() && *f == target ? f - nums.begin() : -1;
    }
};

// non-STL (AC)
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > target)
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};