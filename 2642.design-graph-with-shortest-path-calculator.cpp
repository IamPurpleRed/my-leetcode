/*
 * @lc app=leetcode id=2642 lang=cpp
 *
 * [2642] Design Graph With Shortest Path Calculator
 */

// @lc code=start
class Graph {
  public:
    vector<vector<pair<int, int>>> g;

    Graph(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for (auto edge : edges) g[edge[0]].emplace_back(edge[1], edge[2]);
    }

    void addEdge(vector<int> edge) {
        g[edge[0]].emplace_back(edge[1], edge[2]);
    }

    int shortestPath(int node1, int node2) {
        int n = g.size();
        vector<int> distances(n, INT_MAX);
        distances[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, node1});

        while (!pq.empty()) {
            int currentNode = pq.top().second;
            int currentCost = pq.top().first;
            pq.pop();

            if (currentCost > distances[currentNode]) continue;

            if (currentNode == node2) return currentCost;

            for (auto edge : g[currentNode]) {
                int neighbor = edge.first, distanceToNeighbor = edge.second;
                int neighborCost = distanceToNeighbor + currentCost;
                if (distances[neighbor] > neighborCost) {
                    distances[neighbor] = neighborCost;
                    pq.push({neighborCost, neighbor});
                }
            }
        }

        return (distances[node2] == INT_MAX) ? -1 : distances[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// @lc code=end
