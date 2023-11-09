/*
 * @lc app=leetcode id=1845 lang=cpp
 *
 * [1845] Seat Reservation Manager
 */

// @lc code=start
class SeatManager {
  private:
    priority_queue<int, vector<int>, greater<int>> seat;

  public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) seat.push(i);
    }

    int reserve() {
        int rt = seat.top();
        seat.pop();

        return rt;
    }

    void unreserve(int seatNumber) {
        seat.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
// @lc code=end
