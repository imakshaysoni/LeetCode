class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));

        for (auto it : edges) {
            int i = it[0];
            int j = it[1];
            int wt = it[2];
            matrix[i][j] = wt;
            matrix[j][i] = wt;  // Since the graph is undirected
        }

        for (int i = 0; i < n; i++) {
            matrix[i][i] = 0;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        int minCities = INT_MAX;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            int reachableCities = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] <= distanceThreshold) {
                    reachableCities++;
                }
            }
            if (reachableCities <= minCities) {
                minCities = reachableCities;
                ans = i;
            }
        }

        return ans;
    }
};
