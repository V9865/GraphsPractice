class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int curr){
        visited[curr] = true;
        for(auto &neighbour: adj[curr]){
            if(!visited[neighbour]){
                dfs(adj, visited, neighbour);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(adj, visited, i);
            }
        }
        return count;
    }
};