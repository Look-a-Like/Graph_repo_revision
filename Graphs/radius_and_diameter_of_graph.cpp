#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> graph;

unordered_map<int, int> bfs(int start) {
    unordered_map<int, int> distance;
    queue<pair<int, int>> q;

    q.push({start, 0});
    distance[start] = 0;

    while (!q.empty()) {
        int current_vertex = q.front().first;
        int current_distance = q.front().second;
        q.pop();

        for (int neighbor : graph[current_vertex]) {
            if (distance.find(neighbor) == distance.end()) {
                distance[neighbor] = current_distance + 1;
                q.push({neighbor, current_distance + 1});
            }
        }
    }

    return distance;
}

int diameter_of_graph() {
    int max_diameter = 0;

    for (auto& kv : graph) {
        int start_vertex = kv.first;
        unordered_map<int, int> distances = bfs(start_vertex);

        int max_distance = 0;
        for (auto& dist : distances) {
            max_distance = max(max_distance, dist.second);
        }

        max_diameter = max(max_diameter, max_distance);
    }

    return max_diameter;
}

int radius_of_graph() {
    int min_radius = INT_MAX;

    for (auto& kv : graph) {
        int start_vertex = kv.first;
        unordered_map<int, int> distances = bfs(start_vertex);

        int max_distance = 0;
        for (auto& dist : distances) {
            max_distance = max(max_distance, dist.second);
        }

        min_radius = min(min_radius, max_distance);
    }

    return min_radius;
}

int main() {
    graph = {
        {0, {1, 2}},
        {1, {0, 3}},
        {2, {0, 3}},
        {3, {1,2,4}},
        {4, {3}},
    };

    cout << "Diameter of the graph: " << diameter_of_graph() << endl;
    cout << "Radius of the graph: " << radius_of_graph() << endl;

    return 0;
}
