class Solution {
public:
     bool dfsCycleDetection(vector<vector<int>> &adj, vector<bool> &visited, int curr, int parent){
        visited[curr] = true;
        for(int i=0; i<adj[curr].size(); i++){
            int next = adj[curr][i];
            if(!visited[adj[curr][i]]){
                if(dfsCycleDetection(adj, visited, next, curr)){
                    return true;
                }
            }
            else if(next!=parent){
                return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> test(edges.size()+1);
        for(int i=0; i<edges.size(); i++){
            vector<bool> visited(edges.size()+1, false);
            vector<int> curr = {edges[i][0], edges[i][1]};
            test[edges[i][0]].push_back(edges[i][1]);
            test[edges[i][1]].push_back(edges[i][0]);
            if(dfsCycleDetection(test, visited, edges[i][0], -1)){
                return curr;
            }
        }
        return {};
    }
};