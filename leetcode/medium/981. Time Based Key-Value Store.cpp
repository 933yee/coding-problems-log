class TimeMap {
    unordered_map<string, vector<pair<string, int>>> mp;

   public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end())
            return "";

        int l = 0, r = mp[key].size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int val = mp[key][m].second;
            if (timestamp < val)
                r = m - 1;
            else if (timestamp > val)
                l = m + 1;
            else
                return mp[key][m].first;
        }
        if (l - 1 == -1)
            return "";
        else
            return mp[key][l - 1].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */