// brute force (TLE)
// 對於每一個位置，計算該位置擁有的水量
// 算出這個位置左邊的最大值和右邊的最大值
// 取兩者最小值並減去該位置擁有的高度
class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size(), ret = 0;
        for (int i = 0; i < n - 1; i++) {
            int maxL = *max_element(height.begin(), height.begin() + i);
            int maxR = *max_element(height.begin() + i + 1, height.end());
            ret += max(0, min(maxL, maxR) - height[i]);
        }
        return ret;
    }
};

// dp, prefix max (AC)
// 預先計算區間最大值
class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size(), ret = 0;
        vector<int> maxL{height[0]}, maxR{height[n - 1]};
        for (int i = 1; i < n; i++) {
            maxL.push_back(max(maxL[i - 1], height[i]));
            maxR.push_back(max(maxR[i - 1], height[n - 1 - i]));
        }
        for (int i = 1; i < n - 1; i++) {
            ret += max(0, min(maxL[i - 1], maxR[n - i - 2]) - height[i]);
        }
        return ret;
    }
};

// two pointers (AC)
class Solution {
   public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, maxR = 0, maxL = 0, ret = 0;
        while (l <= r) {
            if (maxR > maxL) {
                ret += max(0, maxL - height[l]);
                maxL = max(maxL, height[l++]);
            } else {
                ret += max(0, maxR - height[r]);
                maxR = max(maxR, height[r--]);
            }
        }
        return ret;
    }
};