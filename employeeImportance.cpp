class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> d;
        for (auto& e : employees) {
            d[e->id] = e;
        }
        function<int(int)> dfs = [&](int i) -> int {
            int s = d[i]->importance;
            for (int j : d[i]->subordinates) {
                s += dfs(j);
            }
            return s;
        };
        return dfs(id);
    }
};
