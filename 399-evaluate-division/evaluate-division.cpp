class Solution {
public:
    double dfs(string curr, string dest, unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> &visited, double product){
        if(curr==dest){
            return product;
        }
        visited.insert(curr);
        for(auto &[neighbour, w]: adj[curr]){
            if(visited.count(neighbour)==0){
                double result = dfs(neighbour, dest, adj, visited, product*w);
                if(result!=-1){
                    return result;
                }
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> adj(equations.size() + 1);
        for (int i=0; i<equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 1/w});
        }
        vector<double> answers;
        for(int i=0; i<queries.size(); i++){
            string src = queries[i][0];
            string dest = queries[i][1];
            unordered_set<string> visited;
            if (!adj.count(src) || !adj.count(dest)) {
                answers.push_back(-1);
                continue;
            }
            answers.push_back(dfs(src, dest, adj, visited, 1));
        }
        return answers;
    }
};