class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e8);
        dist[src] = 0;
        for (int i = 0; i<=k; i++){
            vector<int> temp = dist;
            for (auto it: flights) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u]!=1e8 && (dist[u] + wt)<temp[v]){
                    temp[v] = dist[u] + wt;
                }
            }
            dist = temp;
        }
        if (dist[dst] == 1e8) return -1;
        return dist[dst];
    }
};