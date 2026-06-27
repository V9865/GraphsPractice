class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }
        vector<int> numOfTrusts(n+1, 0);
        vector<int> numOfTrusted(n+1, 0);
        for(int i=0; i<trust.size(); i++){
            numOfTrusts[trust[i][1]]++;
            numOfTrusted[trust[i][0]]++;
        }
        for(int i=0; i<=n; i++){
            if(numOfTrusted[i]==0 && numOfTrusts[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};