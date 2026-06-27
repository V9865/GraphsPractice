class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        vector<int> degree(numRows, 0);
        for(int i=0; i<numRows; i++){
            for(int j=0; j<numRows; j++){
                if(matrix[i][j]==1) degree[i]++;
            }
        }
        return degree;
    }
};