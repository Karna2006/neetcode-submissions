class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstrowzero= false;
        int m=matrix.size();
        int n= matrix[0].size();

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(matrix[r][c]==0){
                    if(r==0){
                        firstrowzero=true;
                    }
                    else{
                        matrix[r][0]=0;
                    }
                    matrix[0][c]=0;
                }
            }
        }

        for(int r=1;r<m;r++){
            for(int c=1;c<n;c++){
                if(matrix[r][0]==0 || matrix[0][c]==0){
                    matrix[r][c]=0;
                }
            }
        }

        if(matrix[0][0]==0){
            for(int r=0;r<m;r++) matrix[r][0]=0;
        }
        if(firstrowzero){
            for(int c=0;c<n;c++)matrix[0][c]=0;
        }
    }
};
