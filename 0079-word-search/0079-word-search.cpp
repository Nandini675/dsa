class Solution {
public:
bool find(int i, int j,int idx, string& word,vector<vector<char>>& board){
  int n= board.size();
    int m= board[0].size();
    if(idx==word.length()) return true;
    if(i<0||j<0||j>=m||i>=n|| board[i][j]!=word[idx]) return false; 

    char temp= board[i][j];
    board[i][j] ='1';
     bool ans= find(i+1,j,idx+1,word,board)||find(i-1,j,idx+1,word,board)||
     find(i,j+1,idx+1,word,board)||find(i,j-1,idx+1,word,board);// up||down||ryt||left
      board[i][j]= temp;
      return  ans;
}
    bool exist(vector<vector<char>>& board, string word) {
    int n= board.size();
    int m= board[0].size();
     for( int i=0;i<n;i++)  {
         for( int j=0;j<m;j++){
            if(board[i][j]==word[0] && find(i,j,0,word,board)) return true;
         }
     }
     return false;
    }
};