class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> car;
        int n = position.size(), ret = 0;
        double mx = 0.0;

        for (int i = 0; i < n; i++) {
            double time = (target - position[i]) / (double)speed[i];
            car.push_back({position[i], time});
        }
        sort(car.begin(), car.end());

        for (int i = n - 1; i >= 0; i--) {
            if (car[i].second > mx) {
                ++ret;
                mx = car[i].second;
            }
        }
        return ret;
    }
};