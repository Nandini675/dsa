class Solution {
public:

void solve(int col,     vector<string> &board,vector<int>&leftrow,vector<int>&upperdiagonal,vector<int>&lowerdiagonal,vector<vector<string>>&ans, int n){
     if(col==n){
 ans.push_back(board);
 return;
     }
      for( int r=0;r<n;r++){
         if(leftrow[r]==0 && lowerdiagonal[r+col]==0 && upperdiagonal[n-1+col-r]==0){
            board[r][col]='Q';
            leftrow[r]=1;
            lowerdiagonal[r+col]=1;
            upperdiagonal[n-1+col-r]=1;
            solve(col+1,board,leftrow,upperdiagonal,lowerdiagonal,ans,n);
           board[r][col] = '.';
            leftrow[r]=0;
            lowerdiagonal[r+col]=0;
            upperdiagonal[n-1+col-r]=0;
         }
      }
}
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>>ans;
      string s(n,'.');
    vector<string> board(n);
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
     vector<int> leftrow(n,0), upperdiagonal(2*n-1,0), lowerdiagonal(2*n-1,0);
     solve( 0,board,leftrow,upperdiagonal, lowerdiagonal,ans ,n);
return ans;


    }
};