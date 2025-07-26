class disjointset{
     public:
     vector<int>size,parent;
    
     disjointset(int n){
         size.resize(n+1,1);
     parent.resize(n+1);
         for(int i=0;i<n;i++){
           parent[i]=i;
         }

     }
      int findultparent(int node){
         if(node== parent[node]) return node;
         return parent[node]= findultparent(parent[node]);
      }
       void  unionbysize(int u,int v){
         int ultp_v= findultparent(v);
         int ultp_u= findultparent(u);
          if(ultp_u == ultp_v) return;
           if(size[ultp_u]< size[ultp_v]){
            parent[ultp_u]= ultp_v;
            size[ultp_v]+= size[ultp_u];
           }
           else{
            parent[ultp_v]= ultp_u;
            size[ultp_u]+= size[ultp_v];
           }

       }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
       int n= grid.size();
        disjointset ds(n*n);
        //step 1 saare connected components banaye
        for(int i=0;i<n;i++) {
             for(int j=0;j<n;j++){
                 if(grid[i][j]==0) continue;
                  int dy[4]={-1,0,1,0};
                   int dx[4]={0,1,0,-1};
                    for(int idx=0;idx<4;idx++){
                         int nr= i+dy[idx];
                         int nc= j+dx[idx];
             if( nc>=0&& nc<n&& nr>=00&& nr<n&& 
             grid[nr][nc]==1){
                 int adjnode= nr*n+nc;
                 int node= i*n+j;
                 ds.unionbysize(node, adjnode);
             }

                    }
             }
        }
        // step 2 0->1
         int mx=0;
           for(int i=0;i<n;i++) {
             for(int j=0;j<n;j++){
                 if(grid[i][j]==1) continue;
                  int dy[4]={-1,0,1,0};
                   int dx[4]={0,1,0,-1};
                   unordered_set<int>comp;
                    for(int idx=0;idx<4;idx++){
                         int nr= i+dy[idx];
                         int nc= j+dx[idx];
             if( nc>=0&& nc<n&& nr>=00&& nr<n&& 
             grid[nr][nc]==1){
                 
                 comp.insert(ds.findultparent(nr*n+nc));
             }

                    }
                     int totsize=0;
                    for(auto it:comp){
                        totsize+= ds.size[it];
                    }
                    mx= max(mx,totsize+1 );

             }
        }
        // in case grid mai sab 1 hi present ho toh
         for(int  i=0;i<n*n;i++){
            mx= max(mx,ds.size[ds.findultparent(i)]);

         }
         return mx;
    }
};