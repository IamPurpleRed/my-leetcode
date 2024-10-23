/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
  private:
    vector<int> members;
    vector<int> minimum;

  public:
    MinStack() {
    }

    void push(int val) {
        members.push_back(val);
        if (minimum.empty()) minimum.push_back(val);
        else minimum.push_back(min(*(minimum.end() - 1), val));
    }

    void pop() {
        members.pop_back();
        minimum.pop_back();
    }

    int top() {
        return *(members.end() - 1);
    }

    int getMin() {
        return *(minimum.end() - 1);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
