class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> degree(n);
        if(n==1){
            return {0};
        }
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;

        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(degree[i]==1){
                q.push(i);
                degree[i]--;
            }
        }
        vector<int> middleNodes;
        while(!q.empty()){
            int size = q.size();
            middleNodes.clear();
            for(int i=0; i<size; i++){
                int node = q.front();
                q.pop();
                middleNodes.push_back(node);
                for(int neighbour: adj[node]){
                    degree[neighbour]--;
                    if(degree[neighbour]==1){
                        q.push(neighbour);
                    }
                }
            }
        }
    return middleNodes;                
    }
};