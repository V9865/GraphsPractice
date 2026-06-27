class Solution {
public:

    bool dfsValidPath(vector<vector<int>> &adj, vector<bool> &visited, int curr, int dest){
        if(curr==dest){
            return true;
        }
        if(visited[curr]){
            return false;
        }
        visited[curr] = true;
        for(int i=0; i<adj[curr].size(); i++){
            if(dfsValidPath(adj, visited, adj[curr][i], dest)){
                return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        return dfsValidPath(adj, visited, source, destination);
    }
};