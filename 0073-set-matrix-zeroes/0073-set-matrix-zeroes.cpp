class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_row= false;
        bool first_col= false;
        int n = matrix.size();// row
        int m= matrix[0].size();// col
        // firstrow
         for( int j=0;j<m;j++)  if(matrix[0][j]==0 ) {first_row= true; break;}
         //first col
         for( int i=0;i<n;i++)  if(matrix[i][0]==0 ) {first_col= true; break;}
        //    mark other row and col that need to be zero
         for( int i=1;i<n;i++){
            for( int j=1;j<m;j++){
                 if( matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;

                 }
            }
         }
        //   zero out rows based on marks
         for(int i=1;i<n;i++){
             for(int j=1;j<m;j++){
                 if(matrix[i][0]==0|| matrix[0][j]==0){
                    matrix[i][j]=0;
                 }
             }
            
         }
        
        //   handle first row AND FIRST col
        if (first_row){
    for (int j = 0; j < m; ++j){
        matrix[0][j] = 0;
    }}
if (first_col){
    for (int i = 0; i < n; ++i){
        matrix[i][0] = 0;
    }}
    }
};