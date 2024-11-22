/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap {
  public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        um[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (!um.count(key)) return "";
        auto it = um[key].upper_bound(timestamp);
        if (it == um[key].begin()) return "";
        return (--it)->second;
    }

  private:
    unordered_map<string, map<unsigned int, string>> um;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
