// fast and slow pointers (AC)
// 有重複數字，所以一定有環，且根據題目條件，nums[0]絕對不會在環裡
// 假設開始點到環入口的距離為 m ，環的長度為c
// 當slow和fast相遇時，slow走了n，因為fast的速度是slow的兩倍，所以fast走了2n
// fast比slow多走n，同時也是多走k圈，所以n % c == 0
// 當slow和fast相遇時，slow在環裡走了n - m，也就是說如果slow再多走m，就會到達環的入口
class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        int start = 0;
        while (start != slow) {
            slow = nums[slow];
            start = nums[start];
        }
        return slow;
    }
};

// binary search (AC)
// 由於nums裡面的值為1 ~ n
// 所以假如今天在檢查數字3是否重複，只要把nums遍歷一遍，找出<= 3數字的數量 k
// 如果k <= 3，代表3以內的數字都沒有重複，這時可以縮小搜尋的範圍 (l = m + 1)
// 反之如果 k > 3，代表 3 或 3 以內的數字出現重複，舉個例子
// 1 2 2 3 ，這時 k 為 4 ，3 或 3以出現重複
// 1 3 4 4 ，這時 k 為 2 ，可以縮小搜尋範圍至 3 以上
class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            int cnt = 0;
            for (int& i : nums) {
                if (m >= i)
                    cnt++;
            }
            if (cnt <= m)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};

// bits (AC)
// 檢查正常情況的所有 bit，如果某個位置算出來的 bit 比正常情況多，就把那個位置的 bit 加入答案中
class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            int cnt1 = 0, cnt2 = 0;
            // normal
            for (int j = 1; j < nums.size(); j++)
                if ((j >> i) & 1)
                    cnt1++;

            // duplicate
            for (int& j : nums)
                if ((j >> i) & 1)
                    cnt2++;

            if (cnt2 > cnt1)
                ret |= (1 << i);
        }
        return ret;
    }
};