class Solution {
public:
    int findCenter(vector<vector<int>>& edge) {
        if(edge.size()==1){
            return 1;
        }
        vector<int> Degree((edge.size()+2), 0);
        for(int i=0; i<edge.size(); i++){
            Degree[edge[i][0]]++;
            Degree[edge[i][1]]++;
        }
        for(int i=0; i<edge.size()+2; i++){
            if(Degree[i]==edge.size()){
                return i;
            }
        }
        return -1;
    }
};