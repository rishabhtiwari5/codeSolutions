class Solution {
public:
    void dfs(int source, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& stackVisited, vector<bool>& unsafeNodes) {
        visited[source] = true;
        stackVisited[source] = true;

        for (auto neighbour : graph[source]) {
            if (!visited[neighbour]) {
                dfs(neighbour, graph, visited, stackVisited, unsafeNodes);
            }
            // If the neighbor is in the current stack or is unsafe, mark the current node unsafe
            if (stackVisited[neighbour] || unsafeNodes[neighbour]) {
                unsafeNodes[source] = true;
            }
        }

        stackVisited[source] = false; // Backtrack
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> stackVisited(n, false);
        vector<bool> unsafeNodes(n, false);

        // Run DFS for all nodes
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited, stackVisited, unsafeNodes);
            }
        }

        // Collect all safe nodes
        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (!unsafeNodes[i]) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};
