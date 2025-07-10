class Solution {
public:
 bool isvalid(vector<vector<char>>& board,int row,int col,char c){
     for( int i=0;i<9;i++){
        //uss puri row mai chaick krege
        if(board[row][i]==c) return false;
         //check for that col
         if(board[i][col]==c) return false;
         // 3*3 sub boxes ke liye  row/3, col/3uss box ki strating row and col dega
        //   i/3 se row mai aage badenge .i%3 se col mai aage badenge
          if( board[3*(row/3) +i/3][3*(col/3)+ i%3]==c) return false;
     }
     return true;
 }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);

    }
     bool solve(vector<vector<char>>& board){
         for(int i=0;i<board.size();i++){
            for( int j=0;j<board.size();j++){
                 if(board[i][j]=='.'){

                    for( char c='1';c<='9';c++){
                         if(isvalid(board,i,j,c)){
                         board[i][j]=c;
                        if (solve(board)) return true;
                        else  board[i][j]='.';
                         }
                    }
                    return false;
                 }
            }
         }
         return true;
     }
};
// t.c: worst case mai saare  cells ke liye  9 possiblietes ko check krna hoga:(9^n2)