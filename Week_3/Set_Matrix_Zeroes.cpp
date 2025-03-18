class Solution {
public:

    void nish(vector<vector<int>>&matrix, int r , int c){

        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++){
            matrix[i][c] =0;
        }

        for(int j=0;j<m;j++){
            matrix[r][j] =0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int,int>>pp;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] ==0){
                    pp.push_back({i,j});
                }
            }
        }

        for(auto pair: pp){
            nish(matrix, pair.first, pair.second);
        }
      
    }
};
