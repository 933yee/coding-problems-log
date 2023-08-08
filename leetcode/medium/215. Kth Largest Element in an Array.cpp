// heap (AC)
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        while (--k)
            pq.pop();
        return pq.top();
    }
};

// binary search (AC)
// 這裡的 m = r - (r - l) / 2，因為下面是 l = m ，當輸入為 0, 1 時， m 會等於 l，會有死循環
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = INT_MIN / 2, r = INT_MAX / 2;
        while (l < r) {
            int m = r - (r - l) / 2;
            int cnt = 0;
            for (int& i : nums) {
                if (i >= m)
                    cnt++;
            }

            if (cnt >= k)
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};

// quick select (AC)
// while(i < j && nums[j] >= nums[l]) j--; 和 while(i < j && nums[i] <= nums[l]) i++; 不能換位置
class Solution {
   public:
    int quickSelect(vector<int>& nums, int k, int l, int r) {
        int i = l, j = r;
        while (i < j) {
            while (i < j && nums[j] >= nums[l]) j--;
            while (i < j && nums[i] <= nums[l]) i++;
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[i]);
        if (nums.size() - i > k)
            return quickSelect(nums, k, i + 1, r);
        if (nums.size() - i < k)
            return quickSelect(nums, k, l, i - 1);
        return nums[i];
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k, 0, nums.size() - 1);
    }
};