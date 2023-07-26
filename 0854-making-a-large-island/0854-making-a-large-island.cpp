// THIS IS STRIVERS CODE

class DisjointSet
{
private:
    

public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        

    }
};



class Solution {
    private:
    bool isValid(int row,int col,int n,int m){
        return  row>=0&&row<n&&col>=0&&col<m;
    }
  public:
  
    int largestIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        DisjointSet ds(n*n);
        
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                
                if(grid[row][col]==0)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                for(int idx=0;idx<4;idx++){
                    
                    int nrow=row+dr[idx];
                    int ncol=col+dc[idx];
                    
                    if(isValid(nrow,ncol,n,n)&&grid[nrow][ncol]==1){
                        
                        int nodeNo=n*row+col;
                        int adjNodeNO=n*nrow+ncol;
                        
                        if(ds.findPar(nodeNo) != ds.findPar(adjNodeNO))
                            ds.unionBySize(nodeNo,adjNodeNO);
                        
                    }
                    
                }
                
            }
        }
        int mx=0;
         for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                
                if(grid[row][col]==1)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                set<int>components;
                for(int idx=0;idx<4;idx++){
                    
                    int nrow=row+dr[idx];
                    int ncol=col+dc[idx];
                    
                    if(isValid(nrow,ncol,n,n)&&grid[nrow][ncol]==1){
                        
                        int nodeNo=n*row+col;
                        int adjNodeNO=n*nrow+ncol;
                        components.insert(ds.findPar(nrow*n+ncol));
                        
                    }
                    
                }
                int totalSize=0;
                for(auto it:components){
                    totalSize+=ds.size[it]; // adding the size of all the parents
                }
                
                mx=max(mx,totalSize+1); // 0 ko bhi 1 me convert krenge hypothetically therefore +1
                
            }
        }
        
        for(int cell=0;cell<n*n;cell++){ // agar all 1 honge to , ye sare one return kar dega.
            mx=max(mx,ds.size[ds.findPar(cell)]);
        }
        return mx;
    }
};