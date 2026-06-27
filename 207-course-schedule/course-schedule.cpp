class Solution {
public:
    bool dfsCycleDetection(vector<vector<int>> &adj, vector<bool> &path, vector<bool> &visited, int curr){
        visited[curr] = true;
        path[curr] = true;
        for(int i=0; i<adj[curr].size(); i++){
            if(!visited[adj[curr][i]]){
                if(dfsCycleDetection(adj, path, visited, adj[curr][i])){
                    return true;
                }
            }
            else if(path[adj[curr][i]]){
                return true;
            }
        }
        path[curr] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);
        if(numCourses==1){
            return true;
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfsCycleDetection(adj,visited,path,i))
                    return false;
            }
        }
        return true;
    }
};