class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
         
         vector<vector<pair<int,int>>> adjList(points.size());
         int n = points.size();
         for(int i=0;i<n;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1;j<n;j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x2-x1) + abs(y2-y1);
                adjList[i].push_back({j, dist});
                adjList[j].push_back({i, dist});
            }
         }


        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> visited(points.size(), 0);
        pq.push({0, 0});

        int sum = 0;
        while(!pq.empty()){
            
            int dist = pq.top().first;
            int u = pq.top().second;

            pq.pop();

            if(visited[u]==1) continue;

            sum += dist;
            visited[u]=1;

            for(auto iter: adjList[u]){
                int v = iter.first;
                int wt = iter.second;

                if(visited[v]==0){
                    pq.push({wt, v});
                }
            }

        }
        return sum;
    }
};