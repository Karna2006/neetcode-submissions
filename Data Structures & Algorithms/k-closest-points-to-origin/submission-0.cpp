class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Store pair: {squared_distance, {x, y}}
        // greater<> turns the default Max-Heap into a Min-Heap based on the first element (distance)
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> minHeap;

        for (const auto& point : points) {
            int dist = point[0] * point[0] + point[1] * point[1];
            minHeap.push({dist, point});
        }

        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
