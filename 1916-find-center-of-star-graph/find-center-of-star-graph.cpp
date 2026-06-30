class Solution {
public:
    int findCenter(vector<vector<int>>& edge) {
        if(edge[0][0]==edge[1][0]){
            return edge[0][0];
        }
        else if(edge[0][0]==edge[1][1]){
            return edge[0][0];
        }
        else{
            return edge[0][1];
        }
    }
};